#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <windows.h>
#include <time.h>
using namespace std;
void method1(int width,int microsec){
	for(int i=0;i<=100;i++){
		putchar('\r');
		for(int j=0;j<width*i/100;j++) putchar('-');
		printf("%d%%",i);
		for(int j=0;j<width*(100-i)/100;j++) putchar('-');
		putchar('>');
		fflush(stdout);
		Sleep(microsec);
	}
}
void method2(int width,int microsec){
	for(int i=0;i<=100;i++){
		putchar('\r');
		for(int j=0;j<width*i/100;j++) putchar('-');
		printf("(-V-) I am running ");
        printf("%d%%",i);
		printf("-->");

        fflush(stdout);
		Sleep(rand()%microsec);
	}    
}
int main(){
	//method1(100,100);
    //FILE* temp=stdout;
    //freopen("G:\\Life_of_XDU\\output.txt","w+",stdout);
    //for(int i=0;i<10;i++) putchar(i);
    


    srand(time(0));
	FILE* temp=stdout;
	//stdout=temp;

    method2(60,200);
}
