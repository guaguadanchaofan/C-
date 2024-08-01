#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            ret ^= i;
        }
        for (int i = 0; i < n - 1; i++)
        {
            ret ^= nums[i];
        }
        return ret;
    }
};