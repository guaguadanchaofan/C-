#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int waysToStep(int n) {
        vector<int> dp(n + 1);
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 4;
        int mod = 1e9 + 7;
        dp[1] = 1; dp[2] = 2; dp[3] = 4;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};