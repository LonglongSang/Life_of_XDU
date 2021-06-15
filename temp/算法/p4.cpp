#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
int problem4(std::vector<int>& arr)
{
    int preMin = 0;
    int sum = 0;
    int ans = 0x80000000;
    for(auto &e : arr)
    {
        sum += e;
        ans = std::max(ans, sum - preMin);
        preMin = std::min(sum, preMin);
    }
    return ans;
}
int main()
{
    std::vector<int> arr;
    
}