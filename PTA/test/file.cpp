#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    FILE* st=fopen("G:\\Life_of_XDU\\PTA\\test\\out.cpp","w+r+");
    for(int i=0;i<100;i++) fprintf(st,"%d\n",i);
    int n;
    while(fscanf(st,"%d\n",&n)!=EOF){
        cout<<n<<endl;
    }
    return 0;
} 