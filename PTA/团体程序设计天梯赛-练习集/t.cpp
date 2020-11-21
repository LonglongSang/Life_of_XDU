#include<iostream>
#include<stack>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main(){
	//freopen("G://in.txt","r",stdin);
    int n;
    scanf("%d\n",&n);
    int i,j,k;
    string tmp = "gno";
    int flag;
    int count;
    char ans[100000];
    for(i = 0;i<n;i++){
        stack<char> a,b;
        count = 0;
        j=0;
        flag = 0;
        
        
        scanf("%[^\n]\n",ans);
        
        while(ans[j]){
            if(ans[j] == ',' || ans[j] == '.'){
                flag = 1;
                j++;
                continue;
            }
            if(flag == 0){
                a.push(ans[j]);
            }
            else if(flag == 1){
                b.push(ans[j]);
            }
            j++;
        }
        flag = 1;
        for(j = 0;j<3;j++){
            if(a.top() != tmp[j] || b.top() != tmp[j]){
                flag = 0;
                break;
            }
            a.pop();
            b.pop();
        }
        if(flag == 0){
            printf("Skipped\n");
            continue;
        }
        else if(flag == 1){
            j = 0;
            while(ans[j]){
                if(ans[j] == ' '){
                    count++;
                }
                j++;
            }
            count -= 2;
            for(j = 0,k=0;j<count;k++){
                if(ans[k] == ' '){
                    j++;
                }
                printf("%c",ans[k]);
            }
            printf("qiao ben zhong.\n");
        }
    }
   return 0;
}


