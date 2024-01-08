#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0;
        string ans = "";
        while (end1 >= 0 || end2 >= 0 || next != 0)
        {
            int x = end1 >= 0 ? num1[end1] - '0' : 0;
            int y = end2 >= 0 ? num2[end2] - '0' : 0;
            int add = x + y + next;
            ans.push_back('0' + add % 10);
            next = add / 10;
            end1--;
            end2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};