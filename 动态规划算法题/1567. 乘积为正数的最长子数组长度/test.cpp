#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        auto g = f;
        f[0] = g[0] = 0;
        int ret = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] > 0) {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
            }
            else if (nums[i - 1] < 0) {
                f[i] = g[i - 1] == 0 ? 0 : g[i - 1] + 1;
                g[i] = f[i - 1] + 1;
            }
            ret = max(ret, f[i]);
        }
        return ret;
    }
};