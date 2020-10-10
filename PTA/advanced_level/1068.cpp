#include <iostream>
#include <vector>
using namespace std;
int main(){
	int color_num,fav_order_num,temp,chain_num,count=0,big=0;
	cin>>color_num>>fav_order_num;
	vector<int> fav_order(color_num+1,-1);//用来记录favorite 颜色的排序
	for(int i=0;i<fav_order_num;i++){
		cin>>temp;
		fav_order[temp]=i;
	}
	
	//颜色串输入
	cin>>chain_num;
	vector<int> chain(chain_num);//颜色串
	for(int i=0;i<chain_num;i++){
		cin>>temp;
		if(fav_order[temp]!=-1) chain[count++]=temp;
	}
	chain.resize(count);

	//动态规划寻找最大值
	vector<int> max(color_num+1,0);
	for(int i=count-1;i>=0;i--){
		big=0;
		for(int j=1;j<max.size();j++) if(fav_order[j]>=fav_order[chain[i]] && max[j]>big) big=max[j];
        max[chain[i]]=big+1;	
	}
	
	//找到max最大值并输出
    big=0;
	for(int i=0;i<max.size();i++) if(max[i]>big) big=max[i];
    cout<<big;
	return 0;
}
