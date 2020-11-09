#include <stdio.h>
#include <stdlib.h>
#include "String.h"
//#######构造函数区########
//构造函数1：
//不含任何内容的空字符串
String::String(){
	length = 0;
	size = add;
	arr = (char*)malloc(sizeof(char) * size);
	arr[0] = 0;
}
//构造函数2：
//将字符串大小初始化为_size
String::String(int _size){
	
	length = _size;
	size = _size+add;
	arr = (char*)malloc(sizeof(char) * size);
	arr[length] = 0;
}
//构造函数3：
//字符串大小初始化为_size
//内容都为val
String::String(int _size, char val){
	
	length = _size;
	size = _size + add;
	arr = (char*)malloc(sizeof(char) * size);
	for(int i=0;i<length;i++) arr[i]=val;
	arr[length] = 0;			
}
//构造函数4：
//将字符串初初始化为const char*:b
String::String(const char* b){
	length = strlen(b);
	size = length + add;
	arr = (char*)malloc(sizeof(char) * size);
	for(int i = 0; i < length; i++) arr[i] = b[i];
	arr[length] = 0;
}
//构造函数5：
//将字符串初初始化为char*:b
String::String(char* b){
	length = strlen(b);
	size = length+add;
	arr = (char*)malloc(sizeof(char) * size);
	for(int i = 0; i < length; i++) arr[i] = b[i];
	arr[length] = 0;
}
//构造函数6：
//将字符串初初始化为String:b
String::String(String& b){
	length = b.StrLength();
	size = length+add;
	arr = (char*)malloc(sizeof(char)*size);
	for(int i = 0; i < length; i++) arr[i] = b[i];
	arr[length] = 0;
}

//######辅助函数区##########

//字符串长度函数
int String::strlen(char* a){
    int cnt=0;
    while(*a) a++,cnt++;
    return cnt;
}
int String::strlen(const char* a){
    int cnt=0;
    while(*a) a++,cnt++;
    return cnt;
}



//动态扩容函数：
//如果当前字符串的大小
//大于已分配的实际空间，进行动态扩容
void String::expand(int new_size){
	if(new_size <= size) return;
	arr = (char*)realloc(arr, sizeof(char) * (new_size+add));
	size = new_size + add;
}
//重设大小函数：
//改变字符串的大小（非实际占有空间）
void String::resize(int _length){
	if(_length <= length){
		length = _length;
		arr[length] = 0;
	}else{
		expand(_length);
		length = _length;
	}
}
//尾插函数：
//向字符串最后插入一个字符
void String::push_back(char val){
	expand(length + 1);
	arr[length++] = val;
	arr[length] = 0;
}
//尾删函数：
//删除字符串最后一个字符
void String::pop_back(){
	length -= length == 0 ? 0 : 1;
	arr[length] = 0;
}
//返回字符串的指针，用于输出
char* String::c_str(){
	return arr;
}
//返回字符串的指针，用于输出
char* String::data(){
	return arr;
}
//重载[]，能够通过下标访问字符
char& String::operator[](int index){
	return arr[index];
}


//#######功能区#########
//1、长度函数:
int String::StrLength(){//1
	return length;
}

//2、StrAssign赋值函数
//可以接受的字符串类型：
//String，char*两种
void String::StrAssign(char* b, int len){
	expand(len);
	for(int i = 0; i < len; i++) arr[i] = b[i];
	length = len;
	arr[length] = 0;			
}
void String::StrAssign(char* b){
	StrAssign(b, strlen(b));
}
void String::StrAssign(String & b){//2
	StrAssign(b.data(), b.StrLength());
}
//以下三个函数对符号=进行了重载
//使String使用=进行一般的赋值
//可接受的字符串类型：String,char*,const char*
String& String::operator =(String &b){
	StrAssign(b);
	return *this;
}
String& String::operator =(const char* b){
	StrAssign((char*)b);
	return *this;
}
String& String::operator =(char* b){
	StrAssign(b);
	return *this;
}		


//3、StrConcat函数：
//可接受的字符串类型:
//String，char*,const char*
void String::StrConcat(char* b, int len){
	expand(len + length);
	for(int i = 0; i < len; i++) arr[i+length] = b[i];
	length += len;
	arr[length] = 0;			
}
void String::StrConcat(char* b){
	StrConcat(b, strlen(b));
}
void String::StrConcat(const char* b){
	StrConcat((char*)b, strlen(b));
}
void String::StrConcat(String &b){
	StrConcat(b.data(), b.StrLength());
}

//4：Substr函数：
String String::Substr(int i, int j){
	String ret;
	if(i < 0) return ret;
	for(int a = 0; a < j && i + a < length; a++){
		ret.push_back(arr[i + a]);
	}
	return ret;
}


//5：StrCmp函数：
//可接受的字符串类型：String,char*
//用法：
//String a,b;char * c
//a.StrCmp(b),a.StrCmp(c)
//比较a与b的大小，比较a与c的大小
//a>b则返回1，a=b返回0，a<b返回-1
int String::StrCmp(char* b){
	char* a = arr;
	while(*a && *b && *a == *b) a++, b++;
	if(*a == 0 && *b == 0) return 0;
	if(*a && !*b) return 1;
	if(!*a && *b) return -1;
	if(*a > *b) return 1;
	else return -1;
}
int String::StrCmp(String &str){
	return StrCmp(str.data());
}


//6:StrIndex函数：
//可接受的类型：String,char*
//用法：
//String a,b;
//char* c;const char* d;
//StrIndex(a,b),StrIndex(a,c),StrIndex(a,d)
//分别在a中查找字符串b,c,d
//如果找到返回第一个下标
//如果未找到返回-1
int String::StrIndex(char* b, int offset){
	char* a = arr + offset;
	int index = 0;
	while(*(a + index)){
		char* x = a + index;
		char* y = b;
		while(*x && *y && *x == *y) x++, y++;
		if(!*y) return index;
		index++;				
	}
	return -1;
}
int String::StrIndex(char* b){
	return StrIndex(b, strlen(b));
}
int String::StrIndex(const char* b){
	return StrIndex((char*)b, strlen(b));
}
int String::StrIndex(String& str){
	return StrIndex(str.data(), 0);
}

//7、StrInsert函数：
//用法:
//String a,b;char * c;int index;
//a.StrInsert(b,index),a.StrInsert(c,index);
//向a中index位置插入b(c)
//同时a中index之后的字符向后移动
//如果index<0，index将会赋值为0
//如果index大于等于a的大小
//那么b(c)会被插入到a的末尾
void String::StrInsert(char* str,int index,int offset){
	index = index > length ? length : index;
	index = index < 0? 0 : index;
	expand(offset + length);
	for(int i = length - 1; i >= index; i--) arr[i + offset] = arr[i];
	for(int i = 0; i < offset; i++) arr[i + index] = str[i];
	length += offset;
	arr[length] = 0;
}
void String::StrInsert(char* str, int index){
	StrInsert(str, index, strlen(str));
}		
void String::StrInsert(String &str, int index){
	StrInsert(str.data(), index, str.StrLength());
}



//8、StrDelete函数:
//用法：
//String a;int index,int len;
//a.StrDelete(index,len)
//删除a中由index开始的len个字符
void String::StrDelete(int index, int len){
	if(index >= length || index < 0) return;
	if(index+len >= length){
		length = index;
		arr[length] = 0;
		return;
	}
	for(int i = index + len;i < length; i++) arr[i - len] = arr[i];
	length -= len;
	arr[length] = 0;
}

//9、StrRep函数:
//用法:
//String a;
//a.StrRep(char*/String b,char*/String c)
//将a中的b替换为c
void String::StrRep(char* a, char* b){
	//非递归替换
	if(!*a) return;//如果a是空字符串，直接返回
	int offset = 0;
	int index = StrIndex(a, offset);
	int len_a = strlen(a);
	int len_b = strlen(b);
	while(index != -1){
		StrDelete(index, len_a);
		StrInsert(b, index);
		index = StrIndex(a, offset);
	}
}
void String::StrRep(String &t, char* r){
	StrRep(t.data(), r);
}
void String::StrRep(char* t, String& r){
	StrRep(t, r.data());
}
void String::StrRep(String &t, String&r){
	StrRep(t.data(), r.data());
}