#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ret = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }
                if (dp[i][j])
                    ret++;
            }
        }
        return ret;
    }
};