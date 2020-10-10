	#include<iostream>
	#include<set>
	#include<cstdio>
	using namespace std;
	int main(){
		int money,n;
		scanf("%d %d\n",&money,&n);
		int first,big,weight,second;
		while(n!=0){
			cin>>first>>big>>weight>>second;
			if(weight<=money){
				if((big==1 && second>first) || (big==0 && second<first)){
					money+=weight;
					cout<<"Win "<<weight<<"!  Total = "<<money<<"."<<endl;
				}else{
					money-=weight;
					cout<<"Lose "<<weight<<".  Total = "<<money<<"."<<endl;				
				}
			}else{
				cout<<"Not enough tokens.  Total = "<<money<<"."<<endl;
			}
			if(money==0){
				cout<<"Game Over."<<endl;
				break;
			}
			n--;
		}
		return 0;
	}