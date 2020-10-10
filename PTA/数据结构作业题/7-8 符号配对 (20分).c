#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[1000];
int top=0;
int cnt[256];
int isgood(char now,char want){
	if(top==0 || cnt[want]==0){
		if(now!='>') printf("NO\n?-%c\n",now);
		else printf("NO\n?-*/\n");
	}else if(stack[top-1]!=want){
		while(stack[top-1] !=want) top--;
		if(stack[top]!='<') printf("NO\n%c-?\n",stack[top]);
		else printf("NO\n/*-?\n");
	}else{
		top--;
		cnt[want]--;
		return 1;
	}
	return 0;
}
int main(){
    char line[1000];
    char* endl=".";
    gets(line);
    int i;
    while(strcmp(line,endl)){
        i=0;
        while(line[i]){
            if(line[i]=='(' || line[i]=='[' || line[i]=='{' || (line[i]=='/' && line[i+1]=='*')){
                if(line[i]!='/'){
					stack[top++]=line[i];
					cnt[line[i]]++;
				}else{
					stack[top++]='<';
					cnt['<']++;
					i++;
				}
            }else if(line[i]==')'){
				if(!isgood(')','(')) return 0;
			}else if(line[i]==']'){
				if(!isgood(']','[')) return 0;
			}else if(line[i]=='}'){
				if(!isgood('}','{')) return 0;
			}else if(line[i]=='*' && line[i+1]=='/'){
				if(!isgood('>','<')) return 0;
				i++;
			}
			i++;
        }
        gets(line);
    }
	if(top!=0){
		if(stack[0]!='<') printf("NO\n%c-?\n",stack[0]);
		else printf("NO\n/*-?\n");
	}else{
		printf("YES\n");		
	}
    return 0;
}