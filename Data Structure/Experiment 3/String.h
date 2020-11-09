#ifndef String_H
#define String_H

//你的代码写在这里
class String{
	private:
		int length;	//字符串实际大小
		int size;	//字符串拥有空间大小
		char* arr;	//字符串数据存放
		int add = 20;//字符串额外扩容空间
	public:
		//#######构造函数区#######

		//构造函数1：
		//不含任何内容的空字符串
		String();

		//构造函数2：
		//将字符串大小初始化为_size
		String(int _size);

		//构造函数3：
		//字符串大小初始化为_size
		//内容都为val
		String(int _size, char val);

		//构造函数4
		//将字符串初初始化为const char*:b
		String(const char* b);

		//构造函数5：
		//将字符串初初始化为char*:b
		String(char* b);

		//构造函数6：
		//将字符串初初始化为String:b
		String(String& b);

		//######辅助函数区##########

		//字符串长度函数
		int strlen(char* a);
		int strlen(const char* a);

		//动态扩容函数：
		//如果当前字符串的大小
		//大于已分配的实际空间，进行动态扩容
		void expand(int new_size);

		//重设大小函数：
		//改变字符串的大小（非实际占有空间）
		void resize(int _length);
        
		//尾插函数：
		//向字符串最后插入一个字符
		void push_back(char val);

		//尾删函数：
		//删除字符串最后一个字符
		void pop_back();

		//返回字符串的指针，用于输出
		char* c_str();

		//返回字符串的指针，用于输出
		char* data();

		//重载[]，能够通过下标访问字符
		char& operator[](int index);
		
		
		//#######功能区#########

		//1、长度函数:
		int StrLength();
		
		//2、StrAssign赋值函数
		//可以接受的字符串类型：
		//String，char*两种
		void StrAssign(char* b, int len);
		void StrAssign(char* b);
		void StrAssign(String & b);

		//以下三个函数对符号=进行了重载
		//使String使用=进行一般的赋值
		//可接受的字符串类型：String,char*,const char*
		String& operator =(String &b);
		String& operator =(const char* b);
		String& operator =(char* b);		
		
		//3、StrConcat函数：
		//可接受的字符串类型:
		//String，char*,const char*
		void StrConcat(char* b, int len);
		void StrConcat(char* b);
		void StrConcat(const char* b);
		void StrConcat(String &b);

		//4：Substr函数：
		String Substr(int i, int j);
			
		//5：StrCmp函数：
		//可接受的字符串类型：String,char*
		//用法：
		//String a,b;char * c
		//a.StrCmp(b),a.StrCmp(c)
		//比较a与b的大小，比较a与c的大小
		//a>b则返回1，a=b返回0，a<b返回-1
		int StrCmp(char* b);
		int StrCmp(String &str);
				
		//6:StrIndex函数：
		//可接受的类型：String,char*
		//用法：
		//String a,b;
		//char* c;const char* d;
		//StrIndex(a,b),StrIndex(a,c),StrIndex(a,d)
		//分别在a中查找字符串b,c,d
		//如果找到返回第一个下标
		//如果未找到返回-1
		int StrIndex(char* b, int offset);
		int StrIndex(char* b);
		int StrIndex(const char* b);
		int StrIndex(String& str);
		
		//7、StrInsert函数：
		//用法:
		//String a,b;char * c;int index;
		//a.StrInsert(b,index),a.StrInsert(c,index);
		//向a中index位置插入b(c)
		//同时a中index之后的字符向后移动
		//如果index<0，index将会赋值为0
		//如果index大于等于a的大小
		//那么b(c)会被插入到a的末尾
		void StrInsert(char* str,int index,int offset);
		void StrInsert(char* str, int index);		
		void StrInsert(String &str, int index);

		//8、StrDelete函数:
		//用法：
		//String a;int index,int len;
		//a.StrDelete(index,len)
		//删除a中由index开始的len个字符
		void StrDelete(int index, int len);
		
		//9、StrRep函数:
		//用法:
		//String a;
		//a.StrRep(char*/String b,char*/String c)
		//将a中的b替换为c
		void StrRep(char* a, char* b);
		void StrRep(String &t, char* r);
		void StrRep(char* t, String& r);
		void StrRep(String &t, String&r);
};

#endif