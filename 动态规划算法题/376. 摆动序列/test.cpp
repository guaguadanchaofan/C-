#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> g(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    f[i] = max(g[j] + 1, f[i]);
                }
                if (nums[j] > nums[i])
                {
                    g[i] = max(f[j] + 1, g[i]);
                }
            }
        }
        int ret = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ret = max(ret, max(f[i], g[i]));
        }
        return ret;
    }
};