#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	int count_word=0;
	int len=0;
	if(str.size()==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<str.size();i++){
		if(str[i]=='.'){
			if(len){
                if(count_word++)
                    cout<<" "<<len;
                else
                    cout<<len;
            }
			break;
		}
		if(str[i]!=' '){
			len++;
		}else if(str[i]==' '){
			if(len){
				if(count_word) cout<<" ";
				count_word++;
				
				cout<<len;
			} 
			len=0;
		}
	}
	cout<<endl;
	return 0;
}