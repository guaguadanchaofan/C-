#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};