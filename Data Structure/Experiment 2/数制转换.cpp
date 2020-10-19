//1、数制转换
#include<stdlib.h>
#include <stdio.h>
int stack[30];
//栈
void d2b(long long ori);
//十进制转二进制

int main(){
	long long ori;
	scanf("%lld\n",&ori);
	d2b(ori);
	return 0;
}
void d2b(long long ori){
	//十进制转二进制
	if(ori == 0)
	{//如果ori为0
		
		putchar('0');
		return;
	}else if(ori < 0)
	{//如果ori为负数
		
		putchar('-');
		ori = -ori;
	}
	int top=0;
	while(ori){
		stack[top++] = ori % 2;
		ori /= 2;
	}
	while(top){
		putchar('0' + stack[(top--) - 1]);
	}
}
//1、数制转换 结束