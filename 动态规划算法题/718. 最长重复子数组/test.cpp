#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int m = n1.size();
        int n = n2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int  ret = -1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (n1[i - 1] == n2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};