#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        vector<int> g(n);
        for (int i = 1; i < n; i++)
        {
            f[i] = f[i - 1] + nums[i - 1];
        }
        for (int j = n - 2; j >= 0; j--)
        {
            g[j] = g[j + 1] + nums[j + 1];
        }
        for (int i = 0; i < n; i++)
        {
            if (f[i] == g[i])
                return i;
        }
        return -1;
    }
};