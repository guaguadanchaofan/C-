#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26] = { 0 };
        for (auto ch : p) hash1[ch - 'a']++;
        int hash2[26] = { 0 };
        int m = p.size();
        vector<int> ret;
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            hash2[in - 'a']++;
            if (hash2[in - 'a'] <= hash1[in - 'a'])
            {
                count++;
            }
            if (right - left + 1 > m)
            {
                char out = s[left];
                left++;
                if (hash2[out - 'a'] <= hash1[out - 'a'])
                {
                    count--;
                }
                hash2[out - 'a']--;
            }
            if (count == m)
            {
                ret.push_back(left);
            }
        }
        return ret;
    }
};