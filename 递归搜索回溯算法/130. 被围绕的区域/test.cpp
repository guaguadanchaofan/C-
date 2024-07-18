#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[201][201];
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i][j] == false)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        check[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n && !check[x][y] && board[x][y] == 'O')
            {
                dfs(board, x, y);
            }
        }
    }
};