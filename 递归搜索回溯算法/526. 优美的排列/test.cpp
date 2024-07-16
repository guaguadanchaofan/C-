#define  _CRT_SECURE_NO_WARNINGS
class Solution {
    bool check[16];
    int ret;
public:
    int countArrangement(int n) {
        dfs(n, 1);
        return ret;
    }
    void dfs(int n, int pos)
    {
        if (n + 1 == pos)
        {
            ret++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check[i] && (i % pos == 0 || pos % i == 0))
            {
                check[i] = true;
                dfs(n, pos + 1);
                check[i] = false;
            }
        }
    }
};