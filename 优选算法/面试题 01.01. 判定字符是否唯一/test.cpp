#define  _CRT_SECURE_NO_WARNINGS

class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26)return false;
        int bitmap = 0;
        for (auto ch : astr)
        {
            int i = ch - 'a';
            if (((bitmap >> i) & 1) == 1)return false;
            bitmap |= 1 << i;
        }
        return true;

    }
};