#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int sum = 0;
    int path = 0;
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0);
        return sum;
    }
    void dfs(vector<int>& nums, int pos)
    {
        if (nums.size() == pos)
        {
            sum += path;
            return;
        }
        path = path ^ nums[pos];
        dfs(nums, pos + 1);
        path = path ^ nums[pos];


        dfs(nums, pos + 1);

    }
};