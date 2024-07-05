#define  _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n, 1);
        auto g = f;
        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                f[i] = 1;
                g[i] = f[i - 1] + 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                f[i] = g[i - 1] + 1;
                g[i] = 1;
            }
            ret = max(ret, max(f[i], g[i]));
        }
        return ret;
    }
};