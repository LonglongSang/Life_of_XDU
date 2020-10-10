#include<iostream>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<string>
#include<stdio.h>
#include<set>
using namespace std;

struct node{
	string stu;
	string scl;
	double sco;
	int num;
};



string tl(string a){
	string o="";
	for(int i=0;i<a.length();i++){
		o+=tolower(a[i]);
	}
	return o;
}

bool cmp(node a, node b){
	if(a.sco!=b.sco) return a.sco>b.sco;
	else return a.num==b.num ? a.scl<b.scl: a.num<b.num;
}
map<string,int> m;

int main(){

	int n,gra,cnt=1;
	vector<node> N(cnt);
	string pn,sn;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pn>>gra>>sn;
		sn=tl(sn);
		if(m[sn]==0) {
			m[sn]=cnt++;
			N.resize(cnt);
		}
		N[m[sn]].scl=sn;
		if(pn[0]=='B') N[m[sn]].sco+=gra/1.5;
		else if(pn[0]=='A') N[m[sn]].sco+=gra;
		else if(pn[0]=='T') N[m[sn]].sco+=gra*1.5;
		N[m[sn]].num++;
	}
	for(int i=1;i<cnt;i++) N[i].sco=(int)N[i].sco;
	cout<<cnt-1<<endl;
	sort(N.begin()+1,N.begin()+cnt,cmp);
	int p=1;
	for(int i=1;i<cnt;i++){
		if(i==1) cout<<p<<" "; 
		else {
			if(int(N[i].sco)!=int(N[i-1].sco)) p=i;
			printf("%d ",p);
		}
		cout<<N[i].scl<<" ";
		int t=N[i].sco;
		printf("%d %d\n",t,N[i].num);
	}

	
	return 0;
}
