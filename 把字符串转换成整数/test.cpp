#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int StrToInt(string str) {
        int len = str.length();
        if (len == 0)
            return 0;
        int index = 0;
        long long ans = 0;
        int flag = 1;
        while (str[index] == ' ')
        {
            index++;
        }
        if (str[index] == '-' || str[index] == '+')
        {
            if (str[index] == '-')
            {
                flag = -1;
            }
            index++;
        }
        for (int i = 0; i < len; i++)
        {
            if (index >= len)
            {
                return ans * flag;
            }
            if (!isdigit(str[index]))
            {
                return 0;
            }
            ans = ans * 10 + (str[index] - '0');
            if (index < len)
            {
                index++;
            }
            else
            {
                return ans * flag;
            }
        }
        return ans * flag;
    }
};