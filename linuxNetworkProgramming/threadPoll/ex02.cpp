#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void test(){
    std::cout<<this_thread::get_id()<<std::endl;

}
void k(std::vector<std::thread>& arr){
    for(int i=0;i<arr.size();i++){
        arr[i]=thread(test);
    }
    for(int i=0;i<arr.size();i++) arr[i].join();
}
int main(){
    std::vector<std::thread> arr(4);
    k(arr);
    k(arr);
    k(arr);
    
}