#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
using namespace std;
mutex ex;
unordered_map<int,void*> running;
unordered_set<int> ended;
int threadCircle;
#define MAX 10000
int getIndex(){
    threadCircle=(threadCircle+1)%MAX;
    while(running.find(threadCircle)!=running.end() || ended.find(threadCircle)!=ended.end()){
        threadCircle=(threadCircle+1)%MAX;
    }
    return threadCircle;
}
void test(int index){
    //cout<<index<<endl;
    int t=rand()%600;
    cout<<index<<" will sleep "<<t<<" ms"<<endl;
    this_thread::sleep_for(chrono::milliseconds(t));
    ex.lock();
    ended.insert(index);
    //printf("%d end\n",index);
    ex.unlock();
}
#define N 10
int beg;
void pri(int index){
    double t=(double)(clock()-beg)/CLOCKS_PER_SEC*1000;
    printf("%d end in %.0lf\n",index,t);
}
int main(){
    srand(time(0));
    beg=clock();
    for(int i=0;i<N;i++) {
        int index=getIndex();
        thread* t=new thread(test,index);
        running[index]=(void*)t;
    }
    
    while(running.size()!=0 || ended.size()!=0){
        if(ended.size()){
            ex.lock();
            int index=*ended.begin();
            ((thread*)running[index])->join();
            delete (thread*)running[index];
            pri(index);
            running.erase(index);
            ended.erase(index);
            ex.unlock();
        }
    }
    
}