#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int m, n, k;
    int ret = 0;
    int dx[4] = { -1 , 1 , 0 ,  0 };
    int dy[4] = { 0 , 0 , 1 , -1 };
    bool vis[101][101];
    int movingCount(int threshold, int rows, int cols) {
        m = rows;
        n = cols;
        k = threshold;
        dfs(0, 0);
        return ret;
    }
    void dfs(int i, int j)
    {
        vis[i][j] = true;
        ret++;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y] && check(x, y))
            {
                dfs(x, y);
            }
        }
    }
    bool check(int i, int j)
    {
        int tmp = 0;
        while (i)
        {
            tmp += i % 10;
            i = i / 10;
        }
        while (j)
        {
            tmp += j % 10;
            j = j / 10;
        }
        if (tmp > k)
        {
            return false;
        }
        return true;
    }
};