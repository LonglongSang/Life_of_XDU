#include <Windows.h>
#include <WinSock.h>
#include "E:\\mysql-5.7.13-winx64\\include\\mysql.h"
#include <string>
#include <iostream>

using namespace std;
//#pragma comment(lib,"D:\\Program Files\\MySQL\\MySQL Server 5.6\\lib\\libmysql.lib") 
#pragma comment(lib,"E:\\mysql-5.7.13-winx64\\lib\\libmysql.lib") 
int main()
{
    
    const char user[] = "root";         
    const char pswd[] = "123456";        
    const char host[] = "localhost";    
    const char table[] = "booktik";       
    unsigned int port = 3306;                
    MYSQL myCont;
    MYSQL_RES *result;
    MYSQL_ROW sql_row;
    int res;
    mysql_init(&myCont);
    if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
    {
        mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式
        res = mysql_query(&myCont, "select * from book");//查询
        if (!res)
        {
            result = mysql_store_result(&myCont);
            if (result)
            {
                while (sql_row = mysql_fetch_row(result))//获取具体的数据
                {
                    cout<<"BOOKNAME:" << sql_row[1] << endl;
                    cout<<"    SIZE:" << sql_row[2] << endl;
                }
            }
        }
        else
        {
            cout << "query sql failed!" << endl;
        }
    }
    else
    {
        cout << "connect failed!" << endl;
    }
    if (result != NULL) 
        mysql_free_result(result);
    mysql_close(&myCont);
    system("pause");
    return 0;

}