#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    string path;
    vector<string> ret;
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ret;
    }

    void dfs(string s, int pos)
    {
        if (s.size() == pos)
        {
            ret.push_back(path);
            return;
        }
        char ch = s[pos];
        path.push_back(ch);
        dfs(s, pos + 1);
        path.pop_back();
        if (s[pos] < '0' || s[pos]>'9')
        {
            char tmp = change(ch);
            path.push_back(tmp);
            dfs(s, pos + 1);
            path.pop_back();
        }
    }
    char change(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 32;
        }
        else
        {
            ch += 32;
        }
        return ch;
    }
};