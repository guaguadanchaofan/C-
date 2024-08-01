#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string countAndSay(int n) {

        string ret = "1";
        for (int i = 1; i < n; i++)
        {
            string tmp;
            int len = ret.size();
            for (int left = 0, right = 0; right < len; )
            {
                while (right < len && ret[left] == ret[right]) right++;
                tmp += to_string(right - left) + ret[left];
                left = right;
            }
            ret = tmp;
        }
        return ret;
    }
};