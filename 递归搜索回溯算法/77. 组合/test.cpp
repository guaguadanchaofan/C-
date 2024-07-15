#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<int> path;
    vector<vector<int>> ret;
    int n, k;
public:
    vector<vector<int>> combine(int _n, int _k) {
        n = _n;
        k = _k;
        dfs(1);
        return ret;
    }
    void dfs(int start)
    {
        if (path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    }
};