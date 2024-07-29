#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ret = 0;
        int zero = 0;
        while (right < n)
        {
            if (nums[right] == 0)
            {
                zero++;
            }
            while (zero > k)
            {
                if (nums[left] == 0)
                {
                    zero--;
                }
                left++;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};