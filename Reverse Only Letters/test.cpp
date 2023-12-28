#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool ischar(char a)
    {
        if (('a' <= a && 'z' >= a) || ('A' <= a && 'Z' >= a))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string reverseOnlyLetters(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !ischar(s[begin]))
            {
                begin++;
            }
            while (begin < end && !ischar(s[end]))
            {
                end--;
            }
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return s;
    }
};
