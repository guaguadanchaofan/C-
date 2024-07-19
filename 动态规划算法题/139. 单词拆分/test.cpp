#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> hash;
        for (auto& a : wordDict)hash.insert(a);
        s = ' ' + s;
        vector<bool> dp(n + 1);//创建dp表
        dp[0] = true;//初始化
        //填表
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j >= 1; --j)
            {
                if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};