class String{
    private:
		int length;	//字符串实际大小
		int size;	//字符串拥有空间大小
		char* arr;	//字符串数据存放
		int add = 20;//字符串额外扩容空间
	public:
		String();
		String(int _size);
		String(int _size, char val);
		String(const char* b);
		String(char* b);
		String(String& b);
        int StrLength();
}

int n=100;
String keyword[n];
sort(keyword,keyword+n,[&](String& a,String &b){
    return a.StrLength()<b.StrLength();
});