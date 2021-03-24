#include <stdio.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <thread>
#include <atomic>

//#include <sys/socket.h>
using namespace std;
atomic<int> cnt(0);
void priTime(){
	struct timeval tv;
	gettimeofday(&tv,nullptr);
	printf("%ld 秒 %ld 微秒",tv.tv_sec%100,tv.tv_usec);
}
void th(int i){
	cnt++;
	cout<<cnt<<endl;
	cout<<"线程 "<<i<<"  开始运行时间:";
	priTime();
	cout<<endl;
	sleep(i);
	cout<<"线程 "<<i<<" 睡了 "<<i<<" 秒"<<" 运行结束时间 ";
	priTime();
	cout<<endl;
	cnt--;
}
/**
 * 某次运行输出结果：
	程序开始时间: time: 1616079288 168251
	现在是创建 线程 1 时间是: time: 1616079288 168335
	现在是创建 线程 2 时间是: time: 1616079288 168450
	现在是创建 线程 3 时间是: time: 1616079288 168544
	现在是创建 线程 4 时间是: time: 1616079288 168633
	现在是join 线程 1 时间是: time: 1616079288 168710
	这个是线程 4 begin time is:time: 1616079288 168760
	这个是线程 3 begin time is:time: 1616079288 168804
	这个是线程 2 begin time is:time: 1616079288 168843
	这个是线程 1 begin time is:time: 1616079288 168880
	线程 1 已经睡了 1 秒 现在时间是 time: 1616079289 169045
	现在是join 线程 2 时间是: time: 1616079289 169185
	线程 2 已经睡了 2 秒 现在时间是 time: 1616079290 168987
	现在是join 线程 3 时间是: time: 1616079290 169110
	线程 3 已经睡了 3 秒 现在时间是 time: 1616079291 168941
	现在是join 线程 4 时间是: time: 1616079291 169077
	线程 4 已经睡了 4 秒 现在时间是 time: 1616079292 168898 
 */ 
#define N 10
int main(int argc,char* argv[]){
	//for(int i=0;i<10;i++) priTime(),fputc('\n',stdout);
	cout<<"程序开始时间: ";
	priTime();
	cout<<endl;
	vector<thread> arr(N+1);
	for(int i=N;i>=1;i--){
		cout<<"线程 "<<i<<" 被创建，时间是: ";
		priTime();
		cout<<endl;
		arr[i]=thread(th,i);
		//arr.push_back(k);
	}
	for(int i=N;i>=1;i--){
		cout<<"线程 "<<i<<" 被join了，时间是: ";
		priTime();
		cout<<endl;
		arr[i].detach();
	}
	cout<<"程序结束时间 : ";
	priTime();
	cout<<endl;
	cout<<cnt<<endl;
	while(cnt!=0);
	return 0;
}
