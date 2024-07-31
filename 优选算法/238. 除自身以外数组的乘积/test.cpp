#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> f(n, 1), g(n, 1);
        vector<int> ret;
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            g[i] = g[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            ret.push_back(f[i] * g[i]);
        }
        return ret;
    }
};