#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
        {
            return s;
        }
        int d = numRows * 2 - 2;
        int n = s.size();
        string ret;
        for (int i = 0; i < n; i += d)
        {
            ret += s[i];
        }
        for (int k = 1; k < numRows - 1; k++)
        {
            for (int i = k, j = d - k; i < n || j < n; i += d, j += d)
            {
                if (i < n) ret += s[i];
                if (j < n) ret += s[j];
            }
        }
        for (int i = numRows - 1; i < n; i += d)
        {
            ret += s[i];
        }
        return ret;
    }
};