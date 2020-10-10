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
	int num,full,sum,count,max,small,num_temp;
	scanf("%d %d\n",&num,&full);
	int temp[num];
	num_temp=num;
	double ret;
	while(num_temp!=0){
		input(temp,num);
		count=0;
		sum=0;
		max=-1;
		small=full+1;
		for(int i=1;i<num;i++){
			if(temp[i]>=0 && temp[i]<=full){
				count++;
				sum+=temp[i];
				if(temp[i]>max) max=temp[i];
				if(temp[i]<small) small=temp[i];
			}
		}
		//cout<<"sum is "<<sum<<endl;
		//cout<<"max is "<<max<<endl;
		//cout<<"min is "<<small<<endl;
		//cout<<"count is "<<count<<endl;
		sum=sum-max-small;
		count=count-2;
		sum=(int)(((float)sum/count+(float)temp[0])/2+0.5);
		cout<<sum<<endl;
		num_temp--;
	}

	return 0;
}
	
