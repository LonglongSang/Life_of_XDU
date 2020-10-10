#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int hah[100005];
int arr[1005];
int main(){
	int n,m,x,y,t;
	multimap<int,int> mp;
	mp.clear();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		mp.insert(pair<int,int>(x,y));
		mp.insert(pair<int,int>(y,x));
	}
	for(int i=0;i<m;i++){
		memset(hah,0,sizeof(hah));
			multimap<int,int>::iterator it;
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			scanf("%d",arr+j);
			hah[arr[j]]=1;
		}
		int flag=0;
		
		for(int j=0;j<t;j++){
			it=mp.find(arr[j]);
			if(it!=mp.end()&&hah[it->second]==1){
				flag=1;
				break;
			}
		}
		if(flag==1) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
