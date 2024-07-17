#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[7][7];
    int n, m;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    check[i][j] = true;
                    if (dfs(board, i, j, word, 1))return true;
                    check[i][j] = false;
                }
            }
        }
        return false;
    }
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { 1,-1,0,0 };
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos)
    {
        if (pos == word.size())
        {
            return true;
        }
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && y >= 0 && !check[x][y] && x < m && y < n && board[x][y] == word[pos])
            {
                check[x][y] = true;
                if (dfs(board, x, y, word, pos + 1))return true;
                check[x][y] = false;
            }
        }
        return false;
    }
};