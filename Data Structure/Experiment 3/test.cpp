#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include <iostream>
using namespace std;
int main(){
    
	String a("asdajsdjaskdjaskldjasdakls");
    cout<<1<<" ";
    printf("%s\n",a.c_str());
    String b=a;
    cout<<2<<" ";
    printf("%s\n",b.c_str());
    String c;
    c.StrConcat(a);
    c.pop_back();
    c.pop_back();
    cout<<3<<" ";
    printf("%s\n",c.c_str());
    String d(100,'v');
    d.StrConcat(c);
    printf("%s\n",d.c_str());
    d.StrDelete(10,1000);
    printf("%s\n",d.c_str());
    char k[100]={'a','b','c','d','e','f',0};
    d.StrInsert(k,100);
    printf("%s\n",d.c_str());
    
    //匹配
    String s1("123456789abcdefghigabcdfh");
    String s2("abcdefh");
    printf("%d\n",s1.StrIndex(s2));
    
    //比较
    printf("%d\n",s1.StrCmp(s2));
    
    //替换
    String t1("abc abc bcd efg abc   ");
    String t2("abc");
    String t3("efg ");
    String t4("xxx");
    t1.StrRep(t2,t4);
    printf("%s\n",t1.data());
    t1.StrRep(t3,t4);
    printf("%s\n",t1.data());
    
    String p;
    p="hello world";
    printf("%s\n",p.data());
}