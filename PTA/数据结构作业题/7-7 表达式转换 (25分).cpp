#include <stdio.h>
#include <string.h>
#include <ctype.h>
int s1[100],s2[100],t1,t2,num,cnt;
char line[100];
int change(char a){
	if( a == '+' || a == '-') return 2;
	else if(a == '/' || a == '*') return 1;
	else return 3;
}
int main(){
	gets(line);
    int before = 1;
	
	while(line[cnt]){
		if(isdigit(line[cnt])){
			num = 0;
			while(isdigit(line[cnt])) num = num * 10 + line[cnt++] - '0';
			s1[t1++] = before * num;
			before = 1
		}else if( line[cnt] != ')'){
			while(line[cnt] != '(' && t2 && change(line[cnt]) >= change(s2[t2-1])) s1[t1++] = -s2[--t2];
			s2[t2++] = line[cnt++];
		}else if(line[cnt] == ')'){
			while( s2[t2-1] != '(') s1[t1++] = -s2[--t2];
			t2--;
			cnt++;
		}
	}
    if(!t1) return 0;
	if(s1[0]>=0) printf("%d", s1[0]);
	else printf("%c", -s1[0]);
	while(t2) s1[t1++] = -s2[--t2];
	for(int i=1;i<t1;i++){
		if(s1[i]>=0) printf(" %d", s1[i]);
		else printf(" %c", -s1[i]);
	}
	printf("\n");
	return 0;
}