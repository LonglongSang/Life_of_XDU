#include <bits/stdc++.h> //万能头 
using namespace std;
using ll=long long;
#define N 128
int todigit[N],typ,radix;
char a[20],b[20],c[20];
bool isok(char* a,int radix){
	while(*a){
		if(todigit[*a]>=radix) return false;
		a++;
	}
	return true;
}
void build(){
	for(char i='0';i<='9';i++) todigit[i]=i-'0';
	for(char i='a';i<='z';i++) todigit[i]=i-'a'+10;
}
ll change(char* a,int radix){
	int i=strlen(a);
	ll num=0;
	while(i--)  num=num*radix+todigit[a[i]];
	return num;
}

int main()
{
	scanf("%s %s %d %d",a,b,&typ,&radix);
	build();
	ll x,y;
	if(typ==2){
		strcpy(c,a);
		strcpy(a,b);
		strcpy(b,c);	
	}
	x=change(a,radix);
	for(int i=2;i<=36;i++){
		if(isok(b,i) && change(b,i)==x){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("Impossible\n");
	return 0;
}