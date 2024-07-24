#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int m, n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> mem(m + 1, vector<int>(n + 1));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                ret = max(ret, dfs(matrix, i, j, mem));
            }
        }
        return ret;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& mem)
    {
        if (mem[i][j] != 0)
        {
            return mem[i][j];
        }
        int ret = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y<n && matrix[x][y]>matrix[i][j])
            {
                ret = max(ret, dfs(matrix, x, y, mem) + 1);
            }
        }
        mem[i][j] = ret;
        return ret;
    }
};