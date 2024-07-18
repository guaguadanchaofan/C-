#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[51][51];
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { -1,1,0,0 };
    int ret;
    int count;
    int m, n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !check[i][j])
                {
                    count = 0;
                    dfs(grid, i, j);
                    ret = max(ret, count);
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        check[i][j] = true;
        count++;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1 && !check[x][y])
            {

                dfs(grid, x, y);
            }
        }
    }
};