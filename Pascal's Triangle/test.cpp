#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv(numRows);
        for (int i = 0; i < numRows; i++)
        {
            vv[i].resize(i + 1);
            vv[i][0] = vv[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        return vv;
    }
};