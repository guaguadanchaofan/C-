#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum ^= i;
        }
        for (auto x : nums)
        {
            sum ^= x;
        }
        int diff = 0;
        while (1)
        {
            if (((sum >> diff) & 1) == 1)break;
            else diff++;
        }
        int a = 0, b = 0;
        for (auto x : nums)
        {
            if (((x >> diff) & 1) == 1)b ^= x;
            else a ^= x;
        }
        for (int i = 1; i <= n; i++)
        {
            if (((i >> diff) & 1) == 1) b ^= i;
            else a ^= i;
        }
        return { a,b };
    }
};