#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
            {
                dp[i] += dp[i - 1];
            }
        }
        int hash[26] = { 0 };
        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 'a'] = max(dp[i], hash[s[i] - 'a']);
        }
        int sum = 0;
        for (int i = 0; i < 26; i++)
        {
            sum += hash[i];
        }
        return sum;

    }
};