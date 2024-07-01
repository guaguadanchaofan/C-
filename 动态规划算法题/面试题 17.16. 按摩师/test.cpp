#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        auto g = f;
        if (n == 0)return 0;
        g[0] = 0;
        f[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(g[n - 1], f[n - 1]);
    }
};