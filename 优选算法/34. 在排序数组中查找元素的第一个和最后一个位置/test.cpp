#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        vector<int> ret;
        if (nums.empty())
        {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        //’“◊Û∂Àµ„
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            if (nums[mid] >= target)
            {
                right = mid;
            }
        }
        if (nums[left] == target) ret.push_back(left);
        else ret.push_back(-1);
        left = 0;
        right = nums.size() - 1;
        //’“”“∂Àµ„
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target)
            {
                left = mid;
            }
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        if (nums[left] == target) ret.push_back(left);
        else ret.push_back(-1);
        return ret;
    }
};