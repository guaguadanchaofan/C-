#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int uniquePaths(int m, int n) {
        //1.����dp��
        //2.��ʼ��
        //3.���
        //4.����ֵ

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};