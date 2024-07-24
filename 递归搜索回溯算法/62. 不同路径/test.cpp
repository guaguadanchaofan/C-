#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1.创建dp表
        // 2.初始化
        // 3.填表
        // 4.返回值

        // vector<vector<int>> dp(m+1,vector<int>(n+1));
        // dp[1][0]=1;
        // for(int i=1;i<=m;i++)
        // {
        //     for(int j=1;j<=n;j++)
        //     {
        //         dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //     }
        // }
        // return dp[m][n];
        vector<vector<int>> mem(m + 1, vector<int>(n + 1));

        return dfs(m, n, mem);
    }
    int dfs(int i, int j, vector<vector<int>>& vis) {
        if (vis[i][j] != 0)
        {
            return vis[i][j];
        }
        if (i == 0 || j == 0) {
            vis[i][j] = 0;
            return 0;
        }
        if (i == 1 && j == 1) {
            vis[i][j] = 1;
            return 1;
        }
        vis[i][j] = dfs(i - 1, j, vis) + dfs(i, j - 1, vis);
        return vis[i][j];
    }
};