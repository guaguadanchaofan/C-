#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int hash1[128] = { 0 };
        int hash2[128] = { 0 };
        int kinds = 0;
        for (auto ch : t)
        {
            if (hash1[ch]++ == 0)
                kinds++;
        }
        int ret = INT_MAX;
        int saveleft = -1;
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            hash2[s[right]]++;
            if (hash2[s[right]] == hash1[s[right]])
            {
                count++;
            }
            while (count == kinds)
            {
                if (right - left + 1 < ret)
                {
                    saveleft = left;
                    ret = right - left + 1;
                }
                if (hash2[s[left]]-- == hash1[s[left]])
                {
                    count--;
                }
                left++;
            }
        }
        if (saveleft != -1)
            return s.substr(saveleft, ret);
        else return "";
    }
};