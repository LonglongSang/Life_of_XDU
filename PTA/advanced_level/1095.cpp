#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <stdlib.h>
#include <sstream>
using namespace std;
int toint(string a){
	istringstream b(a);
	int ret;
	b>>ret;
	return ret;
}
struct room{
	int num,total;
};
struct student{
	string name,date;
	int grade;
};
bool cmp(student a,student b){
	if(a.grade!=b.grade) return a.grade>b.grade;
	else return a.name<b.name;
}
void input(vector< vector<student> > &type_infor,int num,string &check,vector<room> &room_infor){
	string name;
	int grade,index,room_id,size;
	for(int i=0;i<num;i++){
		cin>>name>>grade;
		scanf("/n");
		for(int j=0;j<check.length();j++) if(check[j]==name[0]) index=j;
		room_id=toint(name.substr(1,3));
		room_infor[room_id].num++;
		room_infor[room_id].total+=grade;
		size=type_infor[index].size();
		type_infor[index].resize(size+1);
		type_infor[index][size].name=name;
		type_infor[index][size].date=name.substr(4,6);
		type_infor[index][size].grade=grade;
		type_infor[index][size].grade=grade;
	}
	for(int i=0;i<3;i++) sort(type_infor[i].begin(),type_infor[i].end(),cmp);
}
void type_1(vector< vector<student> > &type_infor,string &infor,string &check){
	int index;
	for(int i=0;i<check.length();i++) if(infor[0]==check[i]) index=i;
	for(int i=0;i<type_infor[index].size();i++) cout<<type_infor[index][i].name<<" "<<type_infor[index][i].grade<<endl;
}
void type_2(vector<room> &room_infor,string &infor){
	int room_id=toint(infor);
	if(room_infor[room_id].num==0){
		cout<<"NA"<<endl;
	}else{
		cout<<room_infor[room_id].num<<" "<<room_infor[room_id].total<<endl;
	}
}
bool cmp1(room a,room b){
	return a.num>b.num;
}
bool cmp2(room a,room b){
	if(a.num!=b.num) return a.num>b.num;
	else return a.total<b.total;
}
void type_3(vector< vector<student> > &type_infor,string &infor){
	vector<room> dp(1000);
	int room_id;
	for(int i=0;i<3;i++){
		for(int j=0;j<type_infor[i].size();j++){
			if(type_infor[i][j].date==infor){
				room_id=toint(type_infor[i][j].name.substr(1,3));
				dp[room_id].num++;
				dp[room_id].total=room_id;
			}
		}
	}
	sort(dp.begin(),dp.end(),cmp1);
	for(int i=0;i<1000;i++){
		if(dp[i].num==0){
			dp.resize(i);
			break;
		}
	}
	sort(dp.begin(),dp.end(),cmp2);
	for(int i=0;i<dp.size();i++) printf("%d %d\n",dp[i].total,dp[i].num);
	
}
void output(int num,vector< vector<student> > &type_infor,string &check,vector<room> &room_infor){
	int type;
	string infor;
	int count=1;
	for(int i=0;i<num;i++){
		cin>>type>>infor;
		cout<<"Case "<<count<<": "<<type<<" "<<infor<<endl;
		if(type==1){
			type_1(type_infor,infor,check);
		}else if(type==2){
			type_2(room_infor,infor);
		}else if(type==3){
			type_3(type_infor,infor);
		}
		scanf("\n");
		count++;
	}
}
int main(){
	int stu,query;
	string check="BAT";
	vector<room> room_infor(1000);
	vector< vector<student> > type_infor(3);
	scanf("%d %d\n",&stu,&query);
	input(type_infor,stu,check,room_infor);
	output(query,type_infor,check,room_infor);
	return 0;
}


