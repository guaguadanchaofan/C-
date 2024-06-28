#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 1.创建dp表
        // 2.初始化
        // 3.填表
        // 4.返回值

        // vector<int> dp(cost.size() + 1);
        // dp[0] = dp[1] = 0;
        // for (int i = 2; i <= cost.size(); i++) {
        //     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        // }
        // return dp[cost.size()];

        int n = cost.size();
        vector<int> dp(n);
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[0], dp[1]);
    }
};