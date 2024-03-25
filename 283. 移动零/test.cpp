#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dest = -1;
        int cur = 0;
        while (cur < nums.size())
        {
            if (nums[cur])
                swap(nums[cur], nums[++dest]);
            cur++;
        }
    }
};