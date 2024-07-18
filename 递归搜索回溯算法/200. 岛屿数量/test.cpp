#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[301][301];
    int ret;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !check[i][j])
                {
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        check[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1' && !check[x][y])
            {
                dfs(grid, x, y);
            }
        }

        return;
    }
};