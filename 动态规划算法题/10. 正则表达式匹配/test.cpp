#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        s = ' ' + s;
        p = ' ' + p;
        dp[0][0] = true;
        for (int j = 2; j <= n; j += 2)
            if (p[j] == '*')dp[0][j] = true;
            else break;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j] == '*')
                    dp[i][j] = dp[i][j - 2] || (p[j - 1] == '.' || p[j - 1] == s[i]) && dp[i - 1][j];
                else
                    dp[i][j] = (s[i] == p[j] || p[j] == '.') && dp[i - 1][j - 1];

            }
        }
        return dp[m][n];
    }
};