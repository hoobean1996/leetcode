// leetcode 221
// Maximal Square 

// 给定一个m x n的矩阵，其中包含0和1，找到在这个矩阵中最大的正方形
// 在这个正方形中全部都是1

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int mx = 0;

        // 我们可以把dp[i][j]定义为：从[0][0]到[i][j]形成的矩形中，
        // 以[i][j]为右下角顶点的正方形，边长的最大值
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i=1; i<= m; i++) {
            for(int j=1; j<=n; j++) {
                
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }

                mx = max(mx, dp[i][j]);
            }
        }
            
        return mx * mx;
    }
};