#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    void hanota(vector<int>& a, vector<int>& b, vector<int>& c) {

        dfs(a, b, c, a.size());
    }
    void dfs(vector<int>& a, vector<int>& b, vector<int>& c, int n) {
        if (n == 1) {
            c.push_back(a.back());
            a.pop_back();
            return;
        }
        dfs(a, c, b, n - 1);
        c.push_back(a.back());
        a.pop_back();
        dfs(b, a, c, n - 1);
    }
};