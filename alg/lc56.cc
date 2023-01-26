// leetcode 56
// Merge Intervals

// 合并区间，按照起始点排序，
// 然后不断的合并两个区间即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        
        for(int i=1; i<intervals.size(); i++) {
            vector<int> cur = intervals[i];
            
            if (cur[0] <= prev[1]) {
                prev[1] = max(prev[1], cur[1]);
            } else {
                ans.push_back(prev);
                prev = cur;
            }
        }
        
        ans.push_back(prev);
        return ans;
    }
};