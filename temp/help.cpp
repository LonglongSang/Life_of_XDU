
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

int dp[10000];
map<char,char*> cipher;
char s[100];
void build(){
    for(char i='a';i<='z';i++){
        scanf("%[^\n]",s);
        char* temp=new char[strlen(s)];
        for(int i=0;i<strlen(s);i++) temp[i]=s[i];
        cipher[i]=temp;
    }
}
vector<string> word;
void build_word(string d){
    int i=0,n=d.length();
    while(i<n){
        if(d[i]!=' '){
            string temp;
            while(i<n && d[i]!=' '){
                char* s=cipher[d[i++]];
                while(*s) temp.push_back(*s),s++;
            }
            cout<<temp<<endl;
            word.push_back(temp);
        }else{
            i++;
        }
    }
}
bool isok(int index,string &sequence,string &word){
    if(dp[index-word.length()+1]==0) return false;
    for(int i=0,n=word.length();i<n;i++) if(word[n-i-1]!=sequence[index-i]) return false;
    return true;
}
int total_combinations(string sequence,string dictionary){
    dp[0]=1;
    for(auto &s:word){
        for(int i=s.length(),n=sequence.length();i<n;i++){
            bool good=true;
            if(dp[i-s.length()]==0) continue;
            for(int j=0;j<s.length() && good;j++){
                if(s[j]!=sequence[i-s.length()+j]) good=false;
            }
            if(!good) continue;
            dp[i+1]+=dp[i-s.length()];
        }
    }
    return dp[sequence.length()];
}





int main(){
    build();
}