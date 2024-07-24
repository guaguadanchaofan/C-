#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> mem(n + 1, vector<int>(n + 1));
        return dfs(1, n, mem);
    }

    int dfs(int left, int right, vector<vector<int>>& mem)
    {

        if (left >= right)
        {
            return 0;
        }
        if (mem[left][right] != 0)
        {
            return mem[left][right];
        }
        int ret = INT_MAX;
        for (int head = left; head <= right; head++)
        {
            int x = dfs(left, head - 1, mem);
            int y = dfs(head + 1, right, mem);
            ret = min(ret, head + max(x, y));
        }
        mem[left][right] = ret;
        return ret;
    }
};