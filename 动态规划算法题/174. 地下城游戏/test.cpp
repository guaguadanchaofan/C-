#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {

        int m = d.size();
        int n = d[0].size();
        vector<vector<int>> dp(m + 1, vector(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) - d[i][j];
                dp[i][j] = max(1, dp[i][j]);
            }
        }
        return dp[0][0];
    }
};