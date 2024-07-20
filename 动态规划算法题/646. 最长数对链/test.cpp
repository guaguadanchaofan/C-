#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n, 1);
        sort(pairs.begin(), pairs.end());
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        int ret = 1;
        for (int i = 0; i < n; i++)
        {
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};