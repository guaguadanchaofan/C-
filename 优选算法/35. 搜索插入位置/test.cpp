#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[right] < target) return right + 1;
        if (nums[left] > target) return left;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};