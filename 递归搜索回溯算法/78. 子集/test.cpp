#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
    //void dfs(vector<int>& nums,int pos)
    //{
    //    if(pos == nums.size())
    //    {
    //        ret.push_back(path);
    //        return;
    //    }


    //    path.push_back(nums[pos]);
    //    dfs(nums,pos+1);
    //    path.pop_back();
    //
    //
    //    dfs(nums,pos+1);
    //}
    void dfs(vector<int>& nums, int pos)
    {
        ret.push_back(path);
        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);

            dfs(nums, i + 1);

            path.pop_back();
        }
    }
};