#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int m, n;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { -1, 1, 0, 0 };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ret;
        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> alt(m, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dfs(heights, 0, i, pac);
        }
        for (int j = 0; j < m; ++j) {
            dfs(heights, j, 0, pac);
        }
        for (int i = 0; i < m; ++i) {
            dfs(heights, i, n - 1, alt);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, m - 1, j, alt);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && alt[i][j]) {
                    ret.push_back({ i, j });
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& heights, int i, int j,
        vector<vector<bool>>& vi) {
        vi[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n &&
                heights[i][j] <= heights[x][y] && !vi[x][y]) {
                dfs(heights, x, y, vi);
            }
        }
    }
};