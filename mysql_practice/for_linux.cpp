#include <iostream>
//#include <Windows.h>
//#include <WinSock.h>
//#include "E:\\mysql-5.7.13-winx64\\include\\mysql.h"
#include <mysql/mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


//#pragma comment(lib,"wsock32.lib") 
//#pragma comment(lib,"E:\\mysql-5.7.13-winx64\\lib\\libmysql.lib")
//#pragma comment(lib,"E:\\mysql-5.7.13-winx64\\lib\\libmysql.lib") 


using namespace std;
//#pragma comment(lib,"libmysql.lib")
//#pragma comment(lib,"wsock32.lib")
MYSQL *mysql = new MYSQL; //mysql连接  
MYSQL_FIELD *fd;    //字段列数组  
char field[32][32];    //存字段名二维数组  
MYSQL_RES *res; //这个结构代表返回行的一个查询结果集  
MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列  
char query[150]; //查询语句


int width=50;

void print_left(string&line,int left);//左对齐输出
void print_mid(string& line);//居中输出
void print_edge();//输出边界
char command[10000];
int typ(char* s);


int back(){
    return 0;
}






int col=10;
/*0 main_menu_t: 
    0 store data -> 1
    1 searching and booking -> 2
    2 query people route -> none
    3 quit system -> none
    mp[0]=1,mp[1]=2;
*/
/*1 data_menu_t:
    col*1+0 (0 flight data) -> none
    col*1+1 (1 bus data) -> none
    col*1+2 (2 customer data) -> none
    col*1+3 (3 back to last level) -> none
*/
/*2 booking_menu_t:
    0 flight -> none
    1 bus -> none
    2 person information -> none
    3 back to last menu-> none
*/

vector<int> connetion;
vector<vector<string>> menu;
vector<string> booking_menu_t={"searching and booking","0 flight","1 bus","2 person information","3 back to last menu"};
vector<string> main_menu_t={"main menu","0 store data","1 searching and booking","2 query people route","3 quit system"};
vector<string> data_menu_t={"store data","0 flight data","1 bus data","2 customer data","3 back to last level"};
vector<string> empty;
int mp[1000];
void initialize(){
    menu.push_back(main_menu_t);
    menu.push_back(data_menu_t);
    menu.push_back(booking_menu_t);
    mp[0]=1,mp[1]=2;
}
string author_name="Longlong Sang";
string public_date="2020-12-01";
string kong="";
int main_interface(int index);

int booking(){

    return 1;
}
bool connect(){
    const char user[] = "root";         
    const char pswd[] = "complexpw2134";        
    const char host[] = "localhost";
    const char database[] = "tour";       
    unsigned int port = 3306;
    MYSQL myCont;
    MYSQL_RES *result;
    MYSQL_ROW sql_row;
    int res;
    mysql_init(&myCont);
    if (mysql_real_connect(&myCont, host, user, pswd, database, port, NULL, 0)){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return true;
}
int main()
{
    //initialize();
    //main_interface(0);
    //while(main_interface(0));
    //connect();
    system("pause");
    return 0;
}


















int main_interface(int index){
    if(menu[index].size()==0) return 0;
    int left=0,choice;
    for(int i=1;i<menu[index].size();i++) left=max(left,(int)menu[index][i].length());
    left=(width-left)/2;
    while(1){
        system("cls");
        print_edge();

        print_mid(menu[index][0]);
        print_mid(kong);
        for(int i=1;i<menu[index].size();i++){
            print_left(menu[index][i],left);
        }
        print_mid(kong);
        print_left(author_name,width-author_name.length()-4);
        print_left(public_date,width-author_name.length()-4);
        print_mid(kong);
        print_edge();

        //输入区
        printf("please input your choice:\n");
        printf(".________________________________.\n");
        printf("|________________________________|");
        putchar('\r');
        scanf("%[^\n]",command);
        getchar();
        choice=typ(command);
        if(choice==-1 || choice<0 || choice>=menu[index].size()-1){
            printf("ERROR:invalid input\n");
            Sleep(1000);
        }else if(choice == menu[index].size()-2){
            return 1;
        }else{
            main_interface(mp[index*col+choice]);
        }
    }
    return 1;
}

int typ(char* s){
    int ret=0,i=0;
    while(s[i]){
        if(!isdigit(s[i])) return -1;
        ret=ret*10+s[i]-'0';
        i++;
        if(i>3) return -1;
    }
    return ret;
}
void print_left(string&line,int left){
    putchar('|');
    for(int i=0;i<left;i++) putchar(' ');
    printf("%s",line.data());
    for(int i=0,cap=width-left-line.length();i<cap;i++) putchar(' ');
    putchar('|');
    putchar('\n');
}
void print_mid(string& line){
    putchar('|');
    int x=width-line.length();
    for(int i=0,cap=x/2;i<cap;i++) putchar(' ');
    for(auto& c:line){
        if(isalpha(c)) putchar(toupper(c));
        else putchar(c);
    }
    for(int i=0,cap=x/2+x%2;i<cap;i++) putchar(' ');
    putchar('|');
    putchar('\n');    
}
void print_edge(){
    putchar('+');
    for(int i=0;i<width;i++) putchar('-');
    putchar('+');
    putchar('\n');
}