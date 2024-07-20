#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, vector<int>> hash;
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]].push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(n));
        int sum = 0;
        for (int j = 2; j < n; j++)//固定倒数第一个数
        {
            for (int i = 1; i < j; i++)//枚举倒数第二个数
            {
                long long a = (long long)nums[i] * 2 - nums[j];
                if (hash.count(a))
                {
                    for (auto k : hash[a])
                    {
                        if (k < i)
                        {
                            dp[i][j] += dp[k][i] + 1;
                        }
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};