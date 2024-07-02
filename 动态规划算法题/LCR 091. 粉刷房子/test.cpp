#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int N = costs.size();
        vector<vector<int>> dp(N + 1, vector<int>(3));
        for (int i = 1; i <= N; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i - 1][2];
        }
        return min(min(dp[N][0], dp[N][1]), dp[N][2]);
    }
};