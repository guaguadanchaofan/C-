#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        vector<int> g(n + 1);
        f[0] = g[0] = 0;
        int max_ = INT_MIN;
        int min_ = INT_MAX;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);
            max_ = max(max_, f[i]);
            min_ = min(min_, g[i]);
            sum += nums[i - 1];
        }
        if (sum != min_)
            return max(max_, sum - min_);
        return max_;
    }
};