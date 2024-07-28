#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4)
        {

        }
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                int  left = j + 1;
                int  right = n - 1;
                long long aim = (long long)target - nums[i] - nums[j];
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (aim == sum)
                    {
                        ret.push_back({ nums[i],nums[left],nums[right],nums[j] });
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])left++;
                        while (left < right && nums[right] == nums[right + 1])right--;
                    }
                    else if (sum > aim)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])j++;

            }
            ++i;
            while (i < n && nums[i] == nums[i - 1])i++;

        }
        return ret;
    }
};