#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    string hash[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    string path;
    vector<string> ret;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)return ret;
        dfs(digits, 0);
        return ret;
    }
    void dfs(string digits, int pos)
    {
        if (digits.size() == pos)
        {
            ret.push_back(path);
            return;
        }
        for (auto ch : hash[digits[pos] - '0'])
        {
            path.push_back(ch);
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};