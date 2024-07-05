#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        if (n <= 1)
        {
            return 0;
        }
        dp[0] = dp[1] = 0;
        int sum = 0;
        for (int i = 2; i < n; i++)
        {
            dp[i] = nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1] ? dp[i - 1] + 1 : 0;
            sum += dp[i];
        }
        return sum;
    }
};