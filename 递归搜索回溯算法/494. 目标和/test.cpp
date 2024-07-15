#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    int ret = 0;
    int target;
public:
    int findTargetSumWays(vector<int>& nums, int _target) {
        target = _target;
        dfs(nums, 0, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos, int num)
    {
        if (nums.size() == pos)
        {
            if (num == target)
            {
                ret++;
            }
            return;
        }
        dfs(nums, pos + 1, num + nums[pos]);
        dfs(nums, pos + 1, num - nums[pos]);
    }
};