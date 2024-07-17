#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool checkcol[9][9];
    bool checkrow[9][9];
    bool checkdig[3][3][9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    checkcol[j][num] = checkrow[i][num] = checkdig[i / 3][j / 3][num] = true;
                }
            }
        }
        dfs(board);
        return;
    }
    bool dfs(vector<vector<char>>& board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (int number = 1; number <= 9; number++)
                    {
                        if (!checkcol[col][number - 1] && !checkrow[row][number - 1] && !checkdig[row / 3][col / 3][number - 1])
                        {
                            checkcol[col][number - 1] = checkrow[row][number - 1] = checkdig[row / 3][col / 3][number - 1] = true;
                            board[row][col] = '0' + number;
                            if (dfs(board) == true)return true;
                            checkcol[col][number - 1] = checkrow[row][number - 1] = checkdig[row / 3][col / 3][number - 1] = false;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};