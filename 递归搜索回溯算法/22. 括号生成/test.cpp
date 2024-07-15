#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    int left = 0;
    int right = 0;
    int _n;
    string path = string();
    vector<string> ret;
public:
    vector<string> generateParenthesis(int n) {
        _n = n;
        dfs();
        return ret;
    }
    void dfs()
    {
        if (right == _n)
        {
            ret.push_back(path);
            return;
        }
        if (left < _n)
        {
            path.push_back('(');
            left++;
            dfs();
            path.pop_back();
            left--;
        }
        if (right < left)
        {
            path.push_back(')');
            right++;
            dfs();
            path.pop_back();
            right--;
        }
    }
};