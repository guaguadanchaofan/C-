#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[51][51];
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { -1,1,0,0 };
    int save;
    int m, n;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        check[sr][sc] = true;
        save = image[sr][sc];
        image[sr][sc] = color;
        dfs(image, sr, sc, color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color)
    {
        for (int k = 0; k < 4; k++)
        {
            int x = sr + dx[k], y = sc + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n && image[x][y] == save && !check[x][y])
            {
                image[x][y] = color;
                cout << '1';
                check[x][y] = true;
                dfs(image, x, y, color);
                check[x][y] = false;
            }
        }
        return;
    }
};