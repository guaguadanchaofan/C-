#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int m, n;
    int dx[8] = { -1, 0, 1, 1, 1, 0,-1,-1 };
    int dy[8] = { -1,-1,-1, 0, 1, 1, 1, 0 };
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if (board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return;
        }
        int count = 0;
        for (int k = 0; k < 8; ++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'M')
            {
                count++;
            }
        }
        if (count)
        {
            board[i][j] = count + '0';
            return;
        }
        else
        {
            board[i][j] = 'B';
            for (int k = 0; k < 8; ++k)
            {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'E')
                {
                    dfs(board, x, y);
                }
            }
        }

    }
};