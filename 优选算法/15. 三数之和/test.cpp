#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n;)
        {
            int left = i + 1;
            int right = n - 1;
            if (nums[i] > 0)break;
            int target = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else if (nums[left] + nums[right] > target)
                {
                    right--;
                }
                else
                {

                    ret.push_back({ nums[i],nums[left],nums[right] });
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])left++;
                    while (left < right && nums[right] == nums[right + 1])right--;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])i++;
        }
        return ret;
    }
};