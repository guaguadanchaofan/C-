#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = n - 1; i >= 2; i--)
        {
            int left = 0;
            int right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    ret = ret + (right - left);
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ret;

    }
};