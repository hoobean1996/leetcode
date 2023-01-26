// leetcode 42
// Traaping water
// 考虑某个位置i的可以容纳的水，它是由左右两个最大值的最小值影响的
// 所以我们利用双指针
// 一开始 leftMax = 0, rightMax = 0
// l .. r
// 每次优先处理较小的那个，因为我们的面积是和最小的有关系的
// if heights[i] >= leftMax 那么就装不下水

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        
        while(l < r) {
            // 因为面积总是与左侧最大值和右侧最大值的最小值相关
            if (height[l] < height[r]) {
                // 由于我们的面积是 min(L, R) - height[i]
                // 如果height[i] >= leftMax -> 无法积水
                // height[l] >= leftMax ? 0 : area
                if (height[l] >= leftMax) {
                    ans += 0;
                    leftMax = height[l];
                }
                else {
                    ans += (leftMax - height[l]);
                }
                l ++;
            }
            else {
                if (height[r] >= rightMax) {
                    ans += 0;
                    rightMax = height[r];
                }          
                else {
                    ans += (rightMax - height[r]);
                }      
                r --;
            }
        }
        
        return ans;
    }
};