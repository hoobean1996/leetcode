// leetcode 146
// LRU Cache 

// LRU Cache 的实现
// 1. 双向链表 list<pair<int, int>> dq + unordered_map<int, list<pair<int, int>>:iterator> ma;
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    list<pair<int, int>> dq;
    // 注意到这里的hash表用的结构是 key -> 
    unordered_map<int, list<pair<int, int>>::iterator> ma;
    int cap = 0;
    
    LRUCache(int capacity) {
        cap = capacity;        
    }
    
    int get(int key) {
        // 如果存在该元素
        if (ma.count(key) > 0) {
            // LRU是每次命中数据以后都会把数据移动到头节点
            int val = ma[key]->second;
            // 删除当前位置的key
            // 并插入到头节点
            dq.erase(ma[key]);
            dq.push_front(make_pair(key, val));
            // 同时更新索引
            ma[key] = dq.begin();
            return val;
        }
        // 如果不存在，直接返回-1
        else return -1;
    }
    
    void put(int key, int value) {
        if (ma.find(key) == ma.end()) {
            if (dq.size() == cap) {
                int last = (dq.back()).first;
                dq.pop_back();
                ma.erase(last);
            }
        }
        else dq.erase(ma[key]);
        
        dq.push_front(make_pair(key, value));
        ma[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */