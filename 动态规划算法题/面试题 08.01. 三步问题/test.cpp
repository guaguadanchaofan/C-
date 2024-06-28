#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int waysToStep(int n) {
        //1.创建dp表
        //2.初始化
        //3.填表
        //4.返回值
        const int mod = 1e9 + 7;

        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        if (n == 3)
        {
            return 4;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; ++i)
        {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};