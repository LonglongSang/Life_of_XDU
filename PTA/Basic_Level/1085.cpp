#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
using namespace std;
struct school{
	vector<int> grade;
	vector<int> student;
};
void conversion(string &a){for(int i=0;i<a.length();i++) if(a[i]>='A' && a[i]<='Z') a[i]=a[i]-'A'+'a';}
int get_index(string &p,string &name){
	for(int i=0;i<3;i++) if(name[0]==p[i]) return i;
	return 1000;
}
void input(	map<string,school> &information,string &p){
	string ID,name;
	int grade,index;
	cin>>ID>>grade>>name;
	conversion(name);
	index=get_index(p,ID);
	map<string,school>::iterator map_p;
	map_p=information.find(name);
	if(map_p==information.end()){
		information[name].grade.resize(3,0);
		information[name].student.resize(3,0);
	}
	information[name].grade[index]+=grade;
	information[name].student[index]++;	
}
void arrangement(map<string,school> &information,map< int,map< int,map< string,int > > > &order){
	map<string,school>::iterator p1;
	map< int,map< int,map< string,int > > >::iterator p2;
	int average=0,stu_num=0;
	for(p1=information.begin();p1!=information.end();p1++){
		average=p1->second.grade[0]/1.5+p1->second.grade[1]+p1->second.grade[2]*1.5;
		stu_num=0;
		for(int i=0;i<3;i++) stu_num+=p1->second.student[i];
		order[average][stu_num][p1->first]++;
	}
}
void output(map< int,map< int,map< string,int > > > &order){
	int count=0,now;
	map< int,map< int,map< string,int > > >::reverse_iterator p1;
	map< int,map< string,int > >::iterator p2;
	map< string,int >::iterator p3;
	for(p1=order.rbegin();p1!=order.rend();p1++){
		now=count+1;
		for(p2=p1->second.begin();p2!=p1->second.end();p2++){
			for(p3=p2->second.begin();p3!=p2->second.end();p3++){
				cout<<now<<" "<<p3->first<<" "<<p1->first<<" "<<p2->first<<endl;
				count+=p3->second;
			}
		}
	}
}
int main(){
	string p="BAT";
	int n;
	scanf("%d\n",&n);
	map<string,school> information;
	for(int i=0;i<n;i++) input(information,p);
	map< int,map< int,map< string,int > > > order;
	arrangement(information,order);
	cout<<information.size()<<endl;
	output(order);
	return 0;
}


