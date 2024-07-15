#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<int> path;
    vector<vector<int>> ret;
    int aim;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        aim = target;
        dfs(candidates, 0, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int num, int pos)
    {
        if (num > aim)
        {
            return;
        }
        if (num == aim)
        {
            ret.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates, num + candidates[i], i);
            path.pop_back();
        }
    }
};