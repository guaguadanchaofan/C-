#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
    bool check[9];
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ret;
    }


    void dfs(vector<int>& nums, int pos)
    {
        if (nums.size() == pos)
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == false && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == false))
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums, pos + 1);
                path.pop_back();
                check[i] = false;
            }

        }

    }
};