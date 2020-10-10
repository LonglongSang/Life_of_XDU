
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

double ch(double a){
	if(a>0){
		a=(double)(int)(a*10+0.5)/10;
	}else if(a==0){
		a=(double)(int)(a*10-0.5)/10;
	}
	return a;
}
void pr1(double a,double b,double c,double d,char e){
	printf("(%.1lf+%.1lfi) %c (%.1lf+%.1lfi) = ",ch(a),ch(b),e,ch(c),ch(d));
}

void pr2(double left,double right){
	if(ch(left)==0 && ch(right)==0){
		cout<<"0.0"<<endl;
	}else if(ch(left)==0){
		printf("%.1lfi\n",right);
	}else if(ch(right)==0){
		printf("%.1lf\n",left);
	}else if(right<0){
		printf("%.1lf%.1lfi\n",left,right);
	}else{
		printf("%.1lf+%.1lfi\n",left,right);
	}
}
int main(){
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	pr1(a,b,c,d,'+');
	pr2(a+c,b+d);
	
	pr1(a,b,c,d,'-');
	pr2(a-c,b-d);
	
	pr1(a,b,c,d,'*');
	pr2(a*c-b*d,a*d+b*c);
	
	pr1(a,b,c,d,'/');
	pr2((a*c+b*d)/(c*c+d*d),(b*c-a*d)/(c*c+d*d));	
	return 0;
}

