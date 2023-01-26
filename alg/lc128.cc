// leetcode 128
// Longest Consecutive Sequence
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        set<int> s = set<int>(nums.begin(), nums.end());
        
        int ans = 0;
        
        for(const int n: nums) {
            if (s.find(n-1) == s.end()) {
                int cur = n;
                int curAns = 1;
                
                while(s.find(cur+1) != s.end()) {
                    cur ++;
                    curAns ++;
                }
                
                ans = max(ans, curAns);
            }
        }
        
        return ans;
    }
};