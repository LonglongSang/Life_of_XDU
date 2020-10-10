#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
struct infor{
	int index;
	int GE,GI;
	double avl_grade;
	vector<int> choice;
};
bool cmp(infor a,infor b){
	if(a.avl_grade!=b.avl_grade) return a.avl_grade>b.avl_grade;
	else return a.GE>b.GE;
}
void input(vector<infor> &stu_infor,int stu,int choice){
	int GE,GI,want;
	for(int i=0;i<stu;i++){
		stu_infor[i].choice.resize(choice);
		cin>>stu_infor[i].GE>>stu_infor[i].GI;
		stu_infor[i].avl_grade=((double)stu_infor[i].GE+(double)stu_infor[i].GI)/2;
		stu_infor[i].index=i;
		for(int j=0;j<choice;j++) cin>>stu_infor[i].choice[j];
		scanf("\n");
	}
	sort(stu_infor.begin(),stu_infor.end(),cmp);
}
void accept_function(vector<infor> &stu_infor,vector<int> &school_limit,vector<int> &school_last_GE,vector<double> &school_last_avl,vector< vector<int> > &accept){
	int want_school;
	for(int i=0;i<stu_infor.size();i++){
		for(int j=0;j<stu_infor[i].choice.size();j++){
			want_school=stu_infor[i].choice[j];
			if(school_limit[want_school]>0){
				accept[want_school].push_back(stu_infor[i].index);
				school_limit[want_school]-=1;
				school_last_GE[want_school]=stu_infor[i].GE;
				school_last_avl[want_school]=stu_infor[i].avl_grade;
				break;
			}else{
				if(school_last_GE[want_school]==stu_infor[i].GE && school_last_avl[want_school]==stu_infor[i].avl_grade){
					accept[want_school].push_back(stu_infor[i].index);
					break;
				}
			}
		}
	}
}
int main(){
	int stu,school_num,choice;
	scanf("%d %d %d\n",&stu,&school_num,&choice);
	vector<int> school_limit(school_num),school_last_GE(school_num);
	vector<double> school_last_avl(school_num);
	vector< vector<int> > accept(school_num);
	vector<infor> stu_infor(stu);
	for(int i=0;i<school_num;i++) cin>>school_limit[i];
	scanf("\n");
	input(stu_infor,stu,choice);
	accept_function(stu_infor,school_limit,school_last_GE,school_last_avl,accept);
	for(int i=0;i<school_num;i++){
		sort(accept[i].begin(),accept[i].end());
		for(int j=0;j<accept[i].size();j++){
			if(j) cout<<" "<<accept[i][j];
			else cout<<accept[i][j];
		}
		cout<<endl;
	}
	return 0;
}


