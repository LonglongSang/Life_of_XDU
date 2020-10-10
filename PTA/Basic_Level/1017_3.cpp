#include <iostream>
#include <vector>
#include <stdio.h>//printf
#include <map>
using namespace std;
int to_int(int hour,int min,int sec){return hour*60*60+min*60+sec;}
bool cal(map<int,int> &counter,int start,int time,int &seven,double &sum){
	map<int,int>::iterator up=counter.begin();
	int next;
	if(start > up->first){
		next=start+time*60;
	}else if(start<= up->first && up->first<= seven){
		sum+=up->first-start;
		next=up->first+time*60;
	}else{
		sum+=up->first-start;
		return true;
	}
	up->second--;
	if(up->second==0) counter.erase(up->first);
	counter[next]++;
	return true;
}
int main(){
	int people,line,hour,min,sec,time,people_count=0,temp;
	scanf("%d %d\n",&people,&line);
	int eight=to_int(8,0,0);
	int seven=to_int(17,0,0);
	map<int,int> counter,dp;
	counter.insert(pair<int,int>(eight,line));
	double sum=0;
	for(int i=0;i<people;i++){
		scanf("%d:%d:%d %d\n",&hour,&min,&sec,&time);
		temp=to_int(hour,min,sec);
		if(time>60) time=60;
		if(temp<=seven)dp.insert(pair<int,int>(temp,time));
	}
	map <int,int>::iterator up;
	for(up=dp.begin();up!=dp.end();up++){
		if(cal(counter,up->first,up->second,seven,sum)) people_count++;
		else break;
	}
	if(people_count==0 || sum==0) printf("0.0\n");
	else printf("%.1lf\n",sum/people_count/60);		
	return 0;
}
