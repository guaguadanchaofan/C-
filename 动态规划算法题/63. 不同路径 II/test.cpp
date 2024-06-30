#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        //1.创建dp表
        //2.初始化
        //3.填表
        //4.返回值
        int m = ob.size();
        int n = ob[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (ob[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};