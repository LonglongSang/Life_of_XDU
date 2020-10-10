using namespace std;
#include <iostream>
int main(){
	int year,hour;
	cin>>year>>hour;
	double payee;
	if(year>=5){
		if(hour<=40){
			payee=50*hour;
			printf("%.2f\n",payee);
		}else{
			payee=50*40+75*(hour-40);
			//cout<<payee<<endl;
			printf("%.2f\n",payee);
		}
	}else{
		if(hour<=40){
			payee=30*hour;
			printf("%.2f\n",payee);
		}else{
			payee=30*40+45*(hour-40);
			printf("%.2f\n",payee);
		}
	}
    return 0;
}