#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string t("croak");
        int n = t.size();
        vector<int> hash(n);
        unordered_map<char, int> index;
        for (int i = 0; i < n; i++)
        {
            index[t[i]] = i;
        }
        for (auto ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                if (hash[n - 1] != 0) hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int i = index[ch];
                if (hash[i - 1] == 0)return -1;;
                hash[i - 1]--;
                hash[i]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (hash[i] != 0)
                return -1;
        }
        return hash[n - 1];
    }
};