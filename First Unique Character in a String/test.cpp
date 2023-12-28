#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        int sz = s.size() - 1;
        for (int i = 0; i <= sz; i++)
        {
            count[s[i] - 'a'] += 1;
        }
        for (int i = 0; i <= sz; i++)
        {
            if (count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};