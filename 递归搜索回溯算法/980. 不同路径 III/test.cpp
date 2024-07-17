#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[21][21];
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { -1,1,0,0 };
    int n, m;
    int stop;
    int ret;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int z, x;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    stop++;
                }
                if (grid[i][j] == 1)
                {
                    z = i;
                    x = j;
                }
            }
        }
        stop += 1;
        check[z][x] = true;
        dfs(grid, z, x, 0);
        return ret;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int count)
    {
        if (grid[i][j] == 2)
        {
            if (count == stop)
            {
                ret++;
                return;
            }
        }

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n && !check[x][y] && grid[x][y] != -1)
            {
                check[x][y] = true;
                dfs(grid, x, y, count + 1);
                check[x][y] = false;
            }
        }

    }
};