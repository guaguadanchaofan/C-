#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<double> f(n + 1);
        auto g = f;
        f[0] = g[0] = 1;
        double ret = INT_MIN;
        for (int i = 1; i <= n; i++) {
            double x = nums[i - 1], y = f[i - 1] * nums[i - 1],
                z = g[i - 1] * nums[i - 1];
            f[i] = max(x, max(y, z));
            g[i] = min(x, min(y, z));
            ret = max(ret, f[i]);
        }
        return static_cast<int>(ret);
    }
};