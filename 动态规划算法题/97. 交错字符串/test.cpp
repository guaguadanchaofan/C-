#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size())
            return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++)
            if (s1[i - 1] == s3[i - 1])dp[i][0] = true;
            else break;
        for (int j = 1; j <= n; j++)
            if (s2[j - 1] == s3[j - 1])dp[0][j] = true;
            else break;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};