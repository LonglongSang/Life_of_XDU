#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }
    struct node{
        string val;
        int cnt;
        node* next;
        node* last;
        node(string& v):val(v)
    }
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {

    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {

    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {

    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 
 */

