#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int uniquePaths(int m, int n) {
        //1.创建dp表
        //2.初始化
        //3.填表
        //4.返回值

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};