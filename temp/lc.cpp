int path[5];
int cnt;
class Solution {
public:
    string tostr(char a){
        string s;
        s.push_back(a);
        return s;
    }
    bool isok(string s){
        bool change=true;
        while(change){
            change=false;
            int cnt=1;
            for(int i=1;i<s.length() && !change;i++){
                if(s[i]==s[i-1]){
                    cnt++;
                }else{
                    if(cnt>=3){
                        s=s.substr(0,i-cnt)+s.substr(i);
                        change=true;
                        break;
                    }
                    cnt=1;
                }
            }
            if(cnt>=3){
                s=s.substr(0,s.length()-cnt);
                change=true;
            }
        }
        return s.length()==0;
    }
    bool dfs(int step,string s,string&hand){
        if(step==cnt){
            cout<<s<<endl;
            return isok(s);
        }
        for(int i=0;i<s.length();i++){
            if(s[i]==hand[path[step]] && dfs(step+1,s.substr(0,i)+tostr(hand[path[step]])+s.substr(i),hand)) return true;
        }
        return false;
    }
    int findMinStep(string board, string hand) {
        int n=hand.length();
        int ans=-1;
        for(int i=0;i<=1<<n;i++){
            int v=i,step=0;
            cnt=0;
            while(v){
                if(v%2) path[cnt++]=step;
                step++;
                v/=2;
            }
            if(dfs(0,board,hand)) ans=ans==-1?cnt:min(ans,cnt);
        }
        return ans;
    }
};