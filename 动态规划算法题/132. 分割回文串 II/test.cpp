#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> check(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                    check[i][j] = i + 1 < j ? check[i + 1][j - 1] : true;
            }
        }
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            if (check[0][i])
                dp[i] = 0;
            else
            {
                for (int j = 1; j <= i; j++)
                {
                    if (check[j][i])
                    {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};