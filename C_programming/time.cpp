#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <unistd.h>
#include <string>
#include <string.h>

//#include <sys/time.h>
using namespace std;
namespace temp{
    struct tm
    {
        int tm_sec;  /*秒，正常范围0-59， 但允许至61*/
        int tm_min;  /*分钟，0-59*/
        int tm_hour; /*小时， 0-23*/
        int tm_mday; /*日，即一个月中的第几天，1-31*/
        int tm_mon;  /*月， 从一月算起，0-11*/
        int tm_year;  /*年， 从1900至今已经多少年*/
        int tm_wday; /*星期，一周中的第几天， 从星期日算起，0-6*/
        int tm_yday; /*从今年1月1日到目前的天数，范围0-365*/
        int tm_isdst; /*日光节约时间的旗标*/
    };
    struct timeval
    {
        long tv_sec; /*秒*/
        long tv_usec; /*微秒*/
    };
};

string week[]={"Sun","Mon","Tues","Wed","Thur","Fri","Sat"};
void priTime(char* typ,struct tm*tmp){
    printf("now is %s time:\n",typ);
    printf("year: %d month: %0.2d day: %0.2d\n",tmp->tm_year+1900,tmp->tm_mon+1,tmp->tm_mday);
    printf("time is:%s %0.2d:%0.2d:%0.2d\n",week[tmp->tm_wday].data(),tmp->tm_hour,tmp->tm_min,tmp->tm_sec);
    putchar('\n');
}

char typ[100];
char* buf;
struct tm* tmp;
int main()
{

    time_t t;
    time(&t);//获得本地时区距离1970年的秒速 time_t time(const time_t* t);

    strcpy(typ,"UTC");
    tmp=gmtime(&t);//struct tm* gmtime(time_t* t);
    buf=asctime(tmp);
    fputs(buf,stdout);
    priTime(typ,tmp);


    strcpy(typ,"local");
    tmp=localtime(&t);//返回当地时间 struct tm* localtime(time_t* t);
    buf=asctime(tmp);//char* asctime(const struct tm* tmp);
    fputs(buf,stdout);
    priTime(typ,tmp);

    time_t k=mktime(tmp);//time_t mktime(const struct tm* tmp);
    
    buf=ctime(&t);//char* ctime(const time_t* t);
    puts(buf);
    buf=ctime(&k);
    puts(buf);
    


    cout<<k<<" "<<t<<" "<<(k-t)<<endl;
    

    

    getchar();
    return 0; 
}