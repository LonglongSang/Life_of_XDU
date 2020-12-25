#include <iostream>
#include <mysql/mysql.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <termio.h>//linux下库函数，这次用于是现在linux下的getch()
/*
This file should be compile in Linux Unbuntu, and you should install Mysql.
<mysql/mysql.h> is support by Mysql library.
This file's Author:Longlong Sang
University: XiDian University
*/



using namespace std;



int width=50,thre=3;//thre是break或返回的阈值
void print_left(string&line,int left,int n,char v);//左对齐输出
void print_mid(string& line);//居中输出
void print_edge();//输出边界
void print_left(char v,int size,int left,int n,char v2);
void main_interface(int index);
bool is_down(char* v,int i);
bool is_up(char* v,int i);
bool is_right(char* v,int i);
bool is_left(char* v,int i);
int getch();
char command[1000];
char mysql_cmd[10000];
char mysql_cmd_arr[100][100];


int col=10;
/*0 main_menu_t: 
    0 store data -> 1
    1 searching and booking -> 2
    2 query people route -> none
    3 quit system -> none
    mp[0]=1,mp[1]=2;
*/
/*1 store_data_t:
    10 col*1+0 (0 flight data) -> none 4
    11 col*1+1 (1 bus data) -> none
    12 col*1+2 (2 customer data) -> none 5
    13 col*1+3 (3 back to last level) -> none
*/
/*2 searching_and_booking_t:
    0 flight -> none
    1 bus -> none
    2 person information -> none
    3 back to last menu-> none
*/
/*3 person_information

*/

/*4 flight_data


*/

vector<int> connetion;
vector<vector<string>> menu;
vector<string> searching_and_booking={"searching and booking","0 flight","1 bus","2 person information","3 back to last menu"};
vector<string> main_menu={"main menu","0 store data","1 searching and booking","2 query people route","3 quit system"};
vector<string> store_data={"store data","0 flight data","1 bus data","2 customer data","3 back to last level"};
vector<string> person_information={"query","person_information","select * from customers"};//func
vector<string> flight_data={"insert","add flight data","flights","flight_id","price","num_seat","num_avail","from_city","to_city"};
vector<string> customer_data={"insert","add customer data","customers","customer_id","name","password"};
vector<string> bus_data={"insert","add bus data","bus","city","price","num_bus","num_avail"};
//flight_data、customer_data、bus_data描述arr[0]表示操作类型，表示插入，arr[1]表示标题、arr[2]表示表名、之后为该表的列名
//INSERT INTO tour.flights (flight_id, price, num_seat, num_avail, from_city, to_city) VALUES (12, 123, 122, 122, 1, 2)

int mp[1000];
void initialize(){
    menu.push_back(main_menu);//0
    menu.push_back(store_data);//1
    menu.push_back(searching_and_booking);//2
    menu.push_back(person_information);//3
    menu.push_back(flight_data);//4
    menu.push_back(bus_data);//5
    menu.push_back(customer_data);//6
    mp[0]=1,mp[1]=2;//0

    mp[col+0]=4,mp[col+1]=5,mp[col+2]=6;
    mp[2*col+2]=3;//2
}
string author_name="Longlong Sang";
string public_date="2020-12-01";
string kong="";

const char* user="root";         
const char* pwd="have changed";        
const char* host="localhost";    
const char* database="tour";       
int port = 3306;
MYSQL my_connect;
MYSQL_RES *result;
MYSQL_ROW sql_row;
bool connect(){
    mysql_init(&my_connect);
    if (mysql_real_connect(&my_connect, host, user, pwd, database, port, NULL, 0)){
        printf("Connect\n");
        return true;
    }else{
        printf("Connext failed\n");
        return false;
    }
}




void query_test();




class insertMethod{

    public:
        const char* back_to_last_level="back to last level";
        const char* submit_data="submit data";
        const char* clear_all_data="clear all data you typing";
        const char* insert_fail="insert fail please check";
        const char* insert_success="insert success";
        
        static const int cnt_size=100;
        int cnt[cnt_size];
        int begin;
        insertMethod(){

        }

        void main_console(int index,int begin){
            this->begin=begin;
            insert_GUI(menu[index]);
        }
        /*
            #define     ESC     "\033"
            #define     UP      "\033[A" 27 91 65
            #define     DOWN    "\033[B" 27 91 66
            #define     LEFT    "\033[D"
            #define     RIGHT   "\033[C"
        */

        int insert_GUI(vector<string>& menu){
            //menu[0] 功能名称(query/insert) menu[1](menu菜单名称) menu[2](表名称) menu[3...menu.size()-1](选项)
            int cursor=0,N=menu.size(),cur,offset=0,right=get_max_len(menu)+3,left=10;
            /*
                cursor 0对应离开，cursor 1对应提交
                cursor 2 -> N 对应menu[3] -> menu[menu.size()-1]这些选项
            */
            bool up,down,can_break,inputting=false,new_circle=true;
            //up标识光标是否向上，down标识光标是否向下
            //can_break标识是否打破while循环，inputting标识现在是否是输入时间
            char v[4];
            while(1){
                if(new_circle){
                    cursor=0,cur=0;
                    memset(v,0,4);
                    memset(cnt,0,cnt_size*sizeof(int));
                    for(int i=0,cap=menu.size();i<cap;i++){
                        //给字符串赋初始值
                        mysql_cmd_arr[i][0]=0;
                    }
                }                
                up=false,down=false,can_break=false,new_circle=false;
                system("clear");
                print_edge();
                print_mid(menu[1]);
                print_edge();
                print_mid(kong);
                //void print(int cursor,int index,int left,int right,char* s1,char* s2)
                print(cursor,0,left,right,(char*)back_to_last_level,mysql_cmd_arr[0]);
                print(cursor,1,left,right,(char*)submit_data,mysql_cmd_arr[1]);
                print(cursor,2,left,right,(char*)clear_all_data,mysql_cmd_arr[2]);
                print_mid(kong);
                print_edge();
                print_mid(kong);
                for(int i=begin;i<menu.size();i++){
                    print(cursor,i-offset,left,right,(char*)menu[i].c_str(),mysql_cmd_arr[i]);
                }
                print_mid(kong);
                print_edge();


                //cursor 1 -> N 对应menu[3] -> menu[menu.size()-1]这些选项
                v[cur]=getch();
				if(cursor==0 && (v[cur]==10 || v[cur]==13)){
					return 1;
				}else if(cursor==1 && (v[cur]==10 || v[cur]==13)){
                    build_query_sentence(menu,mysql_cmd);
                    insert(mysql_cmd);
				}else if(cursor==2 && (v[cur]==10 || v[cur]==13)){
                    new_circle=true;
                }else if(cursor>1){
					if(is_up(v,cur)){
						cnt[cursor+offset]=max(cnt[cursor+offset]-2,0);
						up=true;
					}else if(is_down(v,cur)){
						cnt[cursor+offset]=max(cnt[cursor+offset]-2,0);
						down=true;
					}else if(is_left(v,cur) || is_right(v,cur)){
                        cnt[cursor+offset]=max(cnt[cursor+offset]-2,0);
                    }else if(v[cur]=='\b'){
						cnt[cursor+offset]=max(cnt[cursor+offset]-1,0);
					}else if(v[cur]==10 || v[cur]==13){

					}else{
						mysql_cmd_arr[cursor+offset][cnt[cursor+offset]++]=v[cur];
					}
					mysql_cmd_arr[cursor+offset][cnt[cursor+offset]]=0;
				}else if(is_up(v,cur)){
                    up=true;
                }else if(is_down(v,cur)){
                    down=true;
                }
                cur=(cur+1)%4;
                //sleep(1);
                if(up) cursor=(cursor-1+N)%N;
                else if(down) cursor=(cursor+1)%N;
            }
        }

    private:
        int get_max_len(vector<string>& menu){
            int ret=0;
            for(int i=begin,cap=menu.size();i<cap;i++) ret=max(ret,(int)menu[i].length());
            return ret;
        }
        void insert(const char* com){
            int res=mysql_query(&my_connect,com);
            if(res!=0){
                printf("%s\n",insert_fail);
                getchar();
            }else{
                printf("%s\n",insert_success);
                getchar();
            }
        }        
        void print(int cursor,int index,int left,int right,char* s1,char* s2){
            int total_left=left+right;
            putchar('|');
            for(int i=0,cap=left-((index==cursor)?2:0);i<cap;i++) putchar(' ');
            if(cursor==index) printf("->");
            while(*s1){
                putchar(*s1);
                s1++;
                left++;
            }
            if(index>1) putchar(':'),left++;
            if(index>1) putchar(' '),left++;
            for(int i=left;i<total_left;i++) putchar(' '),left++;
            while(*s2){
                putchar(*s2);
                s2++;
                left++;
            }
            for(int i=left;i<width;i++) putchar(' ');
            putchar('|');
            putchar('\n');
        }
        void build_query_sentence(vector<string>&menu,char* mysql_cmd){
            strcpy(mysql_cmd,"INSERT INTO");
            int len=11,cnt=menu.size()-3;
            mysql_cmd[len++]=' ';
            for(int i=0;i<menu[2].length();i++) mysql_cmd[len++]=menu[2][i];
            mysql_cmd[len++]=' ';
            mysql_cmd[len++]='(';
            for(int i=begin,cap=menu.size();i<cap;i++){
                if(i-begin) mysql_cmd[len++]=',';
                if(i-begin) mysql_cmd[len++]=' ';
                for(auto& v:menu[i]) mysql_cmd[len++]=v;
            }
            strcat(mysql_cmd,") VALUES (");
            len+=10;
            for(int i=begin,cap=menu.size();i<cap;i++){
                if(i-begin) mysql_cmd[len++]=',';
                if(i-begin) mysql_cmd[len++]=' ';
                mysql_cmd[len++]='\"';
                int j=0;
                while(mysql_cmd_arr[i][j]) mysql_cmd[len++]=mysql_cmd_arr[i][j++];
                mysql_cmd[len++]='\"';
            }
            mysql_cmd[len++]=')';
            mysql_cmd[len]=0;
            printf("%s\n",mysql_cmd);
            getchar();
        }
};
//insert_console.main_console(index);
insertMethod insert_console;















int main()
{
    if(!connect()) return 0;
    //query_test();
    initialize();
    main_interface(0);
    //while(main_interface(0));
    //connect();
    //system("pause");
    return 0;
}




bool backspace_check(char* s){
    //if do not have backspace  and do not is empty return true;
    if(*s==0) return false;
    while(*s){
        if(*s=='\b') return false;
        s++;
    }
    return true;
}
bool is_yes(char*s){
    if(!(*s) || *(s+1) || !isalpha(*s)) return false;
    *s=tolower(*s);
    return true; 
}
bool is_jump(char* s){
    int cnt=0;
    while(*s){
        if(*s!='\b') cnt=0;
        else cnt++;
        if(cnt>thre) return true;
        s++;
    }
    return false;
}





   






void query(const char* com){
    MYSQL_RES* res;
    MYSQL_FIELD* col;
    MYSQL_ROW row;
    int r,c,res_num;
    res_num=mysql_query(&my_connect,(const char*)com);
    if(res_num!=0){
        printf("This query failed, maybe not exisit any data\n");
        return;
    }else{
        res=mysql_store_result(&my_connect);
        if(res){
            while(row=mysql_fetch_row(res)){
                cout<<row[1]<<endl;
            }
        }        
    }

}



void query_test(){
    int res=mysql_query(&my_connect,"select * from customers");
    if(!res){
        cout<<res<<endl;
        result=mysql_store_result(&my_connect);
        if(result){
            while(sql_row=mysql_fetch_row(result)){
                cout<<sql_row[1]<<endl;
            }
        }
    }else{
        printf("bad\n");
    }  
}



int query_func(int index){
    system("clear");
    print_edge();
    cout<<"as"<<endl;
    print_mid(menu[index][1]);
    print_edge();
    query(menu[index].back().c_str());
    getchar();
    return 1;
}
bool is_up(char* v,int i){
    return v[i%4]==65 && v[(i+3)%4]==91 && v[(i+2)%4]==27;
}
bool is_down(char* v,int i){
    return v[i%4]==66 && v[(i+3)%4]==91 && v[(i+2)%4]==27;
}
bool is_left(char* v,int i){
    return v[i%4]==68 && v[(i+3)%4]==91 && v[(i+2)%4]==27;
}
bool is_right(char* v,int i){
    return v[i%4]==67 && v[(i+3)%4]==91 && v[(i+2)%4]==27;
}
int get_choose(int index,int N,int left){
    int offset=1,cursor=0;
    char v;
    bool up,down;
    while(1){
        up=false,down=false;
        system("clear");
        print_edge();//输出上边界
        print_mid(menu[index][0]);//输出该界面的名称
        print_mid(kong);//输出一行空行
        for(int i=1;i<menu[index].size();i++){
            if(i-1==cursor%N){
                print_left('-',(int)menu[index][i].length(),left,1,'+');
                print_left(menu[index][i],left,1,'|');
                print_left('-',(int)menu[index][i].length(),left,1,'+');
            }else{
                print_mid(kong);
                print_left(menu[index][i],left,0,' ');
                print_mid(kong);
            }
        }
        /*
        #define     ESC     "\033"
        #define     UP      "\033[A" 27 91 65
        #define     DOWN    "\033[B" 27 91 66
        #define     LEFT    "\033[D"
        #define     RIGHT   "\033[C"
        */
        print_mid(kong);
        print_left(author_name,width-author_name.length()-4,0,' ');
        print_left(public_date,width-author_name.length()-4,0,' ');
        print_mid(kong);
        print_edge();
        int i=0;
        char v[4];
        memset(v,0,4);
        //v[(i+3)%4]!=10 && v[(i+3)%4]!=13 && !up && !down
        while(!up && !down){
            v[i]=getch();
            //printf("%d\n",v[i]);
            if(v[i]==13 || v[i]==10) break;
            else if(is_up(v,i)) up=true;
            else if(is_down(v,i)) down=true;
            //这里用enter键即回车（'\r'==13==CR）来表示结束
            //LF==10=='\n'
            i=(i+1)%4;
        }
        if(up) cursor=(cursor-1+N)%N;
        else if(down) cursor=(cursor+1)%N;
        else break;
    }
    return cursor%N;
}
void GUI(int index){
    int left=0,choice;
    for(int i=1;i<menu[index].size();i++) left=max(left,(int)menu[index][i].length());
    left=(width-left)/2;
    int N=menu[index].size()-1;
    while(1){
        choice=get_choose(index,N,left);
        if(choice==menu[index].size()-2) break;
        else main_interface(mp[index*col+choice]);
    }
}
void main_interface(int index){
    if(menu[index].size()==0) return;
    if(menu[index][0]=="query"){
        query_func(index);
    }else if(menu[index][0]=="insert"){
        insert_console.main_console(index,3);
    }else{
        GUI(index);
    }
}
int getch(void)
{
     struct termios tm, tm_old;
     int fd = 0, ch;
 
     if (tcgetattr(fd, &tm) < 0) {//保存现在的终端设置
          return -1;
     }
 
     tm_old = tm;
     cfmakeraw(&tm);//更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
     if (tcsetattr(fd, TCSANOW, &tm) < 0) {//设置上更改之后的设置
          return -1;
     }
 
     ch = getchar();
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {//更改设置为最初的样子
          return -1;
     }
    
     return ch;
}

void print_left(char v,int size,int left,int n,char v2){
    putchar('|');
    for(int i=0;i<left-n;i++) putchar(' ');
    for(int i=0;i<n;i++) putchar(v2);
    for(int i=0;i<size;i++) putchar(v);
    for(int i=0;i<n;i++) putchar(v2);
    for(int i=0,cap=width-left-size-n;i<cap;i++) putchar(' ');
    putchar('|');
    putchar('\n');
}
void print_left(string&line,int left,int n,char v){
    putchar('|');
    for(int i=0;i<left-n;i++) putchar(' ');
    for(int i=0;i<n;i++) putchar(v);
    printf("%s",line.data());
    for(int i=0;i<n;i++) putchar(v);
    for(int i=0,cap=width-left-line.length()-n;i<cap;i++) putchar(' ');
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
