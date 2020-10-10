#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
void input(int *array,int num){
	int count=0;
	while(num!=0){
		cin>>array[count++];
		num--;
	}
}
int main(){
	int student_num,question_num,sum;
	scanf("%d %d\n",&student_num,&question_num);
	int weight[question_num],answer[question_num],temp[question_num];
	input(weight,question_num);
	input(answer,question_num);
	while(student_num!=0){
		sum=0;
		input(temp,question_num);
		for(int i=0;i<question_num;i++){
			if(temp[i]==answer[i]) sum+=weight[i];
		}
		cout<<sum<<endl;
		student_num--;
	}
	return 0;
}
	
