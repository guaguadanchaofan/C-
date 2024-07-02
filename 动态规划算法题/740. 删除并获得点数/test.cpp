#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 100001;
        int arr[N] = { 0 };
        for (auto x : nums)
        {
            arr[x] += x;
        }
        vector<int> f(N);
        auto g = f;
        f[0] = arr[0];
        g[0] = 0;
        for (int i = 1; i < N; i++)
        {
            f[i] = g[i - 1] + arr[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[N - 1], g[N - 1]);
    }
};