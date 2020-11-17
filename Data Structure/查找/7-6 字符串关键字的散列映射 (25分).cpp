#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n,p;
string val;
int resolve(){
    int ans=0;
    for(int i=1;i<=3 && i<=val.length();i++){
        ans|=(val[val.length()-i]-'A')<<((i-1)*5);
    }
    return ans;

}
bool used[100000];
int placing(){
    int pos=resolve()%p;
    //cout<<pos<<endl;
    int i=0;
    bool ok=false;
    int place=-1;
    while(1){
        place=(pos+i*i)%p;
        if(!used[place]) break;
        place=(pos-i*i+p)%p;
        if(!used[place]) break;        
        i++;
    }
    used[place]=true;
    return place;
}
int main(){
    scanf("%d %d\n",&n,&p);
    unordered_map<string,int> have;
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        cin>>val;
        if(have.find(val)!=have.end()){
            printf("%d",have[val]);
            continue;
        }
        have[val]=placing();
        printf("%d",have[val]);
    }
    return 0;
}