#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool checkcol[10];
    bool checkdig1[20];
    bool checkdig2[20];
    vector<vector<string>> ret;
    vector<string> path;
    int _n;
public:
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n);
        _n = n;
        for (int i = 0; i < n; i++)
        {
            path[i].append(n, '.');
        }
        dfs(0);
        return ret;
    }
    void dfs(int row)
    {
        if (row == _n)
        {
            ret.push_back(path);
            return;
        }
        for (int col = 0; col < _n; col++)
        {
            if (!checkcol[col] && !checkdig1[row - col + _n] && !checkdig2[row + col])
            {
                path[row][col] = 'Q';
                checkcol[col] = checkdig1[row - col + _n] = checkdig2[row + col] = true;
                dfs(row + 1);
                path[row][col] = '.';
                checkcol[col] = checkdig1[row - col + _n] = checkdig2[row + col] = false;

            }
        }
    }
};