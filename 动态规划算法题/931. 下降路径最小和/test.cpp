#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 2, INT_MAX));
        for (int i = 0; i < m + 2; i++)
            dp[0][i] = 0;


        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = min(min(dp[i - 1][j + 1], dp[i - 1][j]), dp[i - 1][j - 1]) + matrix[i - 1][j - 1];
            }
        }

        int ret = INT_MAX;
        for (int i = 1; i <= m; i++)
        {
            ret = min(ret, dp[m][i]);
        }
        return ret;
    }
};