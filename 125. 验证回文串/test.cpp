#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size() - 1;
        if (s.size() == 1)
        {
            return true;
        }
        while (begin < end)
        {
            while (begin < end && !isalnum(s[begin]))
            {
                begin++;
            }
            while (begin < end && !isalnum(s[end]))
            {
                end--;
            }
            if (begin < end)
            {
                if (s[begin] >= 'A' && s[begin] <= 'Z')
                {
                    s[begin] += 32;
                }
                if (s[end] >= 'A' && s[end] <= 'Z')
                {
                    s[end] += 32;
                }
                if (s[begin] != s[end])
                {
                    return false;
                }
            }

            begin++;
            end--;
        }
        return true;
    }
};
int main()
{
    string s("A man, a plan, a canal: Panama");
    cout << isPalindrome(s) << endl;
    return 0;
}