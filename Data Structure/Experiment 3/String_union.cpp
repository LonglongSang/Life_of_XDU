#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
class String{
	private:
		int length=0;	//字符串实际大小
		int size=0;	//字符串拥有空间大小
		char* arr=NULL;	//字符串数据存放
		int add = 20;//字符串额外扩容空间
	public:
		//#######构造函数区########
		//构造函数1：
		//不含任何内容的空字符串
		String(){
			//length = 0;
			//size = add;
			//arr = (char*)malloc(sizeof(char) * size);
			//arr[0] = 0;
		}
		//构造函数2：
		//将字符串大小初始化为_size
		String(int _size){
			
			length = _size;
			size = _size+add;
			arr = (char*)malloc(sizeof(char) * size);
			arr[length] = 0;
		}
		//构造函数3：
		//字符串大小初始化为_size
		//内容都为val
		String(int _size, char val){
			
			length = _size;
			size = _size + add;
			arr = (char*)malloc(sizeof(char) * size);
			for(int i=0;i<length;i++) arr[i]=val;
			arr[length] = 0;			
		}
		//构造函数4：
		//将字符串初初始化为const char*:b
		String(const char* b){
			length = strlen(b);
			size = length + add;
			arr = (char*)malloc(sizeof(char) * size);
			for(int i = 0; i < length; i++) arr[i] = b[i];
			arr[length] = 0;
		}
		//构造函数5：
		//将字符串初初始化为char*:b
		String(char* b){
			length = strlen(b);
			size = length+add;
			arr = (char*)malloc(sizeof(char) * size);
			for(int i = 0; i < length; i++) arr[i] = b[i];
			arr[length] = 0;
		}
		//构造函数6：
		//将字符串初初始化为String:b
    
		String(const String &b){
			length = b.StrLength();
			size = length+add;
			arr = (char*)malloc(sizeof(char)*size);
			for(int i = 0; i < length; i++) arr[i] = b[i];
			arr[length] = 0;
		}
        
        ~String(){
            free(arr);
        }

		//######辅助函数区##########

        //字符串长度函数
        int strlen(char* a){
            int cnt=0;
            while(*a) a++,cnt++;
            return cnt;
        }
        int strlen(const char* a){
            int cnt=0;
            while(*a) a++,cnt++;
            return cnt;
        }

		//动态扩容函数：
		//如果当前字符串的大小
		//大于已分配的实际空间，进行动态扩容
		void expand(int new_size){
			if(new_size <= size) return;
			arr = (char*)realloc(arr, sizeof(char) * (new_size+add));
			size = new_size + add;
		}
		//重设大小函数：
		//改变字符串的大小（非实际占有空间）
		void resize(int _length){
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
		void push_back(char val){
			expand(length + 1);
			arr[length++] = val;
			arr[length] = 0;
		}
		//尾删函数：
		//删除字符串最后一个字符
		void pop_back(){
			length -= length == 0 ? 0 : 1;
			arr[length] = 0;
		}
		//返回字符串的指针，用于输出
		char* c_str()const{
			return arr;
		}
		//返回字符串的指针，用于输出
		char* data()const{
			return arr;
		}
		//重载[]，能够通过下标访问字符
		char& operator[](int index)const{
			return arr[index];
		}
        
		
		
		//#######功能区#########
		//1、长度函数:
		int StrLength()const{//1
			return length;
		}
		
		//2、StrAssign赋值函数
		//可以接受的字符串类型：
		//String，char*两种
		void StrAssign(char* b, int len){
			expand(len);
			for(int i = 0; i < len; i++) arr[i] = b[i];
			length = len;
			arr[length] = 0;			
		}
		void StrAssign(char* b){
			StrAssign(b, strlen(b));
		}
		void StrAssign(String & b){//2
			StrAssign(b.data(), b.StrLength());
		}
		//以下三个函数对符号=进行了重载
		//使String使用=进行一般的赋值
		//可接受的字符串类型：String,char*,const char*
    /*
		String& operator =(String &b){
			StrAssign(b);
			return *this;
		}
		String& operator =(const char* b){
			StrAssign((char*)b);
			return *this;
		}
		String& operator =(char* b){
			StrAssign(b);
			return *this;
		}
        */
		
		
		//3、StrConcat函数：
		//可接受的字符串类型:
		//String，char*,const char*
		void StrConcat(char* b, int len){
			expand(len + length);
			for(int i = 0; i < len; i++) arr[i+length] = b[i];
			length += len;
			arr[length] = 0;			
		}
		void StrConcat(char* b){
			StrConcat(b, strlen(b));
		}
		void StrConcat(const char* b){
			StrConcat((char*)b, strlen(b));
		}
		void StrConcat(String &b){
			StrConcat(b.data(), b.StrLength());
		}

		//4：Substr函数：
		String Substr(int i, int j){
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
		int StrCmp(char* b){
			char* a = arr;
			while(*a && *b && *a == *b) a++, b++;
			if(*a == 0 && *b == 0) return 0;
			if(*a && !*b) return 1;
			if(!*a && *b) return -1;
			if(*a > *b) return 1;
			else return -1;
		}
		int StrCmp(String &str){
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
		int StrIndex(char* b, int offset){
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
		int StrIndex(char* b){
			return StrIndex(b, strlen(b));
		}
		int StrIndex(const char* b){
			return StrIndex((char*)b, strlen(b));
		}
		int StrIndex(String& str){
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
		void StrInsert(char* str,int index,int offset){
			index = index > length ? length : index;
			index = index < 0? 0 : index;
			expand(offset + length);
			for(int i = length - 1; i >= index; i--) arr[i + offset] = arr[i];
			for(int i = 0; i < offset; i++) arr[i + index] = str[i];
			length += offset;
			arr[length] = 0;
		}
		void StrInsert(char* str, int index){
			StrInsert(str, index, strlen(str));
		}		
		void StrInsert(String &str, int index){
			StrInsert(str.data(), index, str.StrLength());
		}



		//8、StrDelete函数:
		//用法：
		//String a;int index,int len;
		//a.StrDelete(index,len)
		//删除a中由index开始的len个字符
		void StrDelete(int index, int len){
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
		void StrRep(char* a, char* b){
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
		void StrRep(String &t, char* r){
			StrRep(t.data(), r);
		}
		void StrRep(char* t, String& r){
			StrRep(t, r.data());
		}
		void StrRep(String &t, String&r){
			StrRep(t.data(), r.data());
		}
		

};
/*
输入格式：
标准输入：第一行n，随后n行，每行一个关键词，关键词不含空格
*/
int main(){
    String line(120);
    char temp[20];
    int n;
    scanf("%d\n",&n);
    String keyword[n];
    for(int i=0;i<n;i++){
        scanf("%[^\n]\n",temp);
        keyword[i].StrAssign(temp);
        //printf("%s\n",keyword[i].data());
        //cout<<keyword[i].StrLength()<<endl;
    }
    //freopen("G:\\text.file","r+",stdin);
    sort(keyword,keyword+n,[&](const String& a,const String& b){
        return a.StrCmp(b)==-1?true:false;
        //return a.StrLength()<b.StrLength();
    });
    for(int i=0;i<n;i++){
        printf("%s\n",keyword[i].data());
        //printf("%s\n",keyword[i].data());
        //cout<<keyword[i].StrLength()<<endl;
    }
    //for(int i=0;i<n;i++) cout<<keyword[i].StrLength()<<endl;
    //for(int i=0;i<n;i++) cout<<keyword[i].data()<<endl;
    //将上一行解注释，读入该文本文件
    //while(scanf("%[^\n]\n",line.data())!=EOF){
    //    
    //}

    return 0;
}