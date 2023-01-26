// leetcode 75
// Sort Colors

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int p0 = 0;
        int cur = 0;
        int p2 = nums.size() - 1;

        while (cur <= p2)
        {
            if (nums[cur] == 0)
                swap(nums[cur++], nums[p0++]);
            else if (nums[cur] == 2)
                swap(nums[cur], nums[p2--]);
            else
                cur++;
        }
    }
};