#include <stdio.h>
#include <queue>
#include <vector>
class Solution{
    private:
        static bool inited;         //表示是否已经初试化，false
        static int offset;          //偏移值，1e5
        static int bitNum[200001];  //bitNum[i]表示i - offset的二进制表示下1的数目
        static int N;               //200001
        int nBits;
        //获得val的二进制表示（补码）中的1的数目
        static int countOne(int val){
            int cnt = (val < 0 ? 1 : 0);//如果为负数，最高位bit位为1
            for(int i = 0; i < 31; i++) cnt += (val >> i) & 1;//获取int型前31位中bit位为1的数目
            return cnt;
        }
        //初始化，计算[-1e5, 1e5]之间的数的二进制下1的数目并存入到bitNum数组中，可以作为缓存，因为实际中握手机制要进行多次
        static void init(){
            if(inited == true) return;//保证一次初始化
            inited = true;
            int val;
            for(int i = 0; i < N; i++){
                val = i - offset;
                bitNum[i] = countOne(val);
            }
        }
        /*
        获取val的二进制下1的数目，作为直接调用，如果传入的数据在[-1e5, 1e5]之间，可直接返回bitNum[val + offset]
        否则返回countOne(val)（当有客户失误传入的数据在[-1e5, 1e5]之外，可以保证不会出现访问越界）
        */
        int getBitNum(int val){
            if(val + offset >= 0 && val + offset < N) return bitNum[val + offset];
            else return countOne(val);
        }

    public:
        //构造函数
        Solution(){
            init();
        }
        //获得答案
        std::vector<int> getSoluton(){
            int n, m, val;
            scanf("num = %d", &n);
            getchar();
            scanf("element = %d", &m);
            std::vector<int> ans(m);
            getchar();
            scanf("streamNum = [");

            auto cmp = [&](int const & a, int const & b)->bool{
                if(getBitNum(a) != getBitNum(b)) return getBitNum(a) > getBitNum(b);
                else return a > b;
            };//比较lambda表达式
            std::priority_queue<int, std::vector<int>, decltype(cmp)> Q(cmp);//优先队列

            for(int i = 0; i < n; i++){
                scanf("%d", &val);
                getchar();//获得逗号
                if(Q.size() < m){
                    //Q的大小小于m，直接存入优先队列中即可
                    Q.push(val);
                }else if(Q.size() && cmp(val, Q.top())){
                    //Q的大小为m，且val的优先级比优先队列的头元素的优先级高
                    Q.pop();
                    Q.push(val);
                }
            }
            while(!Q.empty()){
                ans[--m] = Q.top();
                Q.pop();
            }
            return ans;
        }
};
//静态变量初始化
int Solution::bitNum[200001];
bool Solution::inited = false;
int Solution::offset = 100000;
int Solution::N = 200001;

int main(){
    Solution* s = new Solution();
    std::vector<int> ans = s->getSoluton();
    for(auto &e: ans) printf("%d\n", e);
}