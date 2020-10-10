#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
void go(int i,int & order,int &max,int &max_index,int &count,vector<pair<int,int>> &now,vector<int> &ori){
	while(count!=1){
		if(now[i].first<0){
			i--;
			continue;
		}else{
			if(now[i].first!=max){
				now[i].first=-now[i].second-1;
				now[i].second=order;
				count--;
			}
			i--;
		}
	}
	max=0,max_index=0,count=0;
}
bool cmp(pair<int,int> &a,pair<int,int> &b){return a.second>b.second;}

int main(){
	int num,k,temp;
	scanf("%d %d\n",&num,&k);
	vector<int> ori(num);
	vector<pair<int,int>> now(num);
	scanf("%d",&ori[0]);
	for(int i=1;i<num;i++) scanf(" %d",&ori[i]);
	scanf("\n");
	scanf("%d",&temp);
	now[0]={ori[temp],temp};
	for(int i=1;i<num;i++){
		scanf(" %d",&temp);
		now[i]={ori[temp],temp};
	}
	int count=0,order=1,max,max_index,minus_count;
	while(1){
		count=0;
		max=0;
		minus_count=0;
		for(int i=0;i<num;i++){
			if(now[i].first<0){
                minus_count++;
                continue;
            }
			if(now[i].first>max) max=now[i].first;
			count++;
			if(count==k) go(i,order,max,max_index,count,now,ori);
		}
        if(count!=0) go(num-1,order,max,max_index,count,now,ori);
		if(minus_count==num-1){
            for(int i=0;i<num;i++){
                if(now[i].first>=0){
                    now[i].first=-now[i].second-1;
                    now[i].second=order+1;
                    break;
                }
            }
            break;
        }
		order++;
	}
	sort(now.begin(),now.end(),cmp);
	count=0;
	for(int i=0;i<num;i++){
		if(i>0 && now[i].second==now[i-1].second);
		else count=i+1;
		ori[-now[i].first-1]=count;
	}
	for(int i=0;i<num;i++){
		if(i)  cout<<" "<<ori[i];
		else  cout<<ori[i];
	}
	return 0;
}
































