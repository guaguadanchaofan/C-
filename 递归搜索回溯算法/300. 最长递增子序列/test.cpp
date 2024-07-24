#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n,1);
        // for(int i = 1; i < n; i++)
        // {
        //     for(int j =0 ; j < i;j++)
        //     {
        //         if(nums[i]>nums[j])
        //         {
        //             dp[i] = max(dp[j]+1,dp[i]);
        //         }
        //     }
        // }
        // int ret=INT_MIN;
        // for(int i = 0 ; i<n;i++)
        // {
        //     ret=max(ret,dp[i]);
        // }
        // return ret;
        int ret = 0;
        int n = nums.size();
        vector<int> mem(n + 1);
        for (int i = 0; i < n; i++)
        {
            ret = max(ret, dfs(i, nums, mem));
        }
        return ret;
    }
    int dfs(int pos, vector<int>& nums, vector<int>& mem)
    {
        if (mem[pos] != 0)
        {
            return mem[pos];
        }
        int ret = 1;
        for (int i = pos + 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[pos])
                ret = max(ret, dfs(i, nums, mem) + 1);
        }
        mem[pos] = ret;
        return ret;
    }
};