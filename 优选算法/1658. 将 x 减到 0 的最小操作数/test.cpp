#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (auto a : nums)sum += a;
        int target = sum - x;
        if (target < 0)
            return -1;
        int ret = -1;
        for (int left = 0, right = 0, tmp = 0; right < n; right++)
        {
            tmp += nums[right];
            while (tmp > target)
            {
                tmp -= nums[left++];
            }
            if (tmp == target)
                ret = max(ret, right - left + 1);
        }
        if (ret == -1)return -1;
        else
            return n - ret;
    }
};