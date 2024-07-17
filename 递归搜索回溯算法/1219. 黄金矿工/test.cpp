#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[16][16];
    int dx[4] = { 0 ,0 ,1 ,-1 };
    int dy[4] = { 1 ,-1 ,0 ,0 };
    int m, n;
    int ret;
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    check[i][j] = true;
                    dfs(grid, i, j, grid[i][j]);
                    check[i][j] = false;
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int path)
    {
        ret = max(ret, path);

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 & y >= 0 && x < m && y < n && !check[x][y] && grid[x][y] != 0)
            {
                check[x][y] = true;
                dfs(grid, x, y, path + grid[x][y]);
                check[x][y] = false;
            }
        }

    }
};