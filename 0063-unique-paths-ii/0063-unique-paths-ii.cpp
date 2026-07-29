class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] || grid[m-1][n-1]) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int j = 1; j < n; j++)
            dp[j] = (grid[0][j] == 0) ? dp[j-1] : 0;
            
        for (int i = 1; i < m; i++) {
            dp[0] = (grid[i][0] == 0) ? dp[0] : 0;
            for (int j = 1; j < n; j++)
                dp[j] = (grid[i][j] == 0) ? dp[j] + dp[j-1] : 0;
        }
        return dp[n-1];
    }
};