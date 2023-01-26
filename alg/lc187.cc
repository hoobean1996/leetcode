// leetcode 187
// Repeated DNA Sequences

// 重复的DNA序列
// 由于是长度给定的序列，所以利用Rolling Hash很简单
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int L = 10;
        int n = s.length();

        int a = 4;
        int aL = (int)pow(a, L);
        // 映射到数字
        map<char, int> toInt = {
            {'A', 0},
            {'C', 1},
            {'G', 2},
            {'T', 3}};

        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = toInt[s[i]];

        int h = 0;
        set<int> seen;
        set<string> output;

        for (int start = 0; start < n - L + 1; start++)
        {
            if (start > 0)
            {
                // 参考12345的计算
                // h0 = 1234
                // h1 = 1234 * 10 - 1 * 10^4 + 3
                h = h * a - nums[start - 1] * aL + nums[start + L - 1];
            }
            else
            {
                for (int i = 0; i < L; i++)
                    h = h * a + nums[i];
            }
            if (seen.find(h) != seen.end()) output.insert(s.substr(start, L));
            seen.insert(h);
        }

        return vector<string>(output.begin(), output.end());
    }
};