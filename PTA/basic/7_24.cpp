using namespace std;
#include <iostream>
int main(){
	int a,b;
	scanf("%d/%d",&a,&b);
	if(a==b){
		cout<<1<<"/"<<1<<endl;
		return 0;
	}
	int min;
	int flag=1;
	while(1){
		min=a>b?b:a;
		for(int i=2;i<=min;i++){
			if(a%i==0 && b%i==0){
				a/=i;
				b/=i;
				flag=0;
				break;
			}
		}
		if(flag==1){
			break;
		}else{
			flag=1;
		}
	}
	printf("%d/%d\n",a,b);
    return 0;
}