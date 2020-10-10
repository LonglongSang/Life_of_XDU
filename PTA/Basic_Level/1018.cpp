#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int main(){
	int n,n_temp;
	cin>>n;
	n_temp=n;
	map<char,int> count_a,count_b;
	int count=0;
	char a,b;
	//cout<<n<<endl;
	scanf("\n");
	while(n!=0){
		scanf("%c %c\n",&a,&b);
		//cout<<a<<" "<<b;
		if(a==b){
			count++;
		}else if((a=='B' && b=='C') || (a=='C' && b=='J') || (a=='J' && b=='B')){
			count_a[a]++;
		}else{
			count_b[b]++;
		}
		n--;
	}
	int win=count_a['B']+count_a['C']+count_a['J'];
	//cout<<"win"<<win<<endl;
	printf("%d %d %d\n",win,count,n_temp-win-count);
	printf("%d %d %d\n",n_temp-win-count,count,win);
	char max_a,max_b;
	int max=-1;
	for(auto it=count_a.begin();it!=count_a.end();it++){
		if(it->second > max) max_a=it->first;
		//cout << it->first << " " << it->second << endl;
	}
	max=-1;
	for(auto it=count_b.begin();it!=count_b.end();it++){
		//cout << it->first << " " << it->second << endl;
		if(it->second > max) max_b=it->first;
	}
	cout<<max_a<<" "<<max_b<<endl;
	return 0;
}