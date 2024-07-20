#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> count(n, 1);
        int retlen = 1;
        int retcount = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (len[j] + 1 == len[i])count[i] += count[j];
                    else if (len[j] + 1 > len[i])len[i] = len[j] + 1, count[i] = count[j];
                }
            }
            if (retlen == len[i])retcount += count[i];
            else if (retlen < len[i])retlen = len[i], retcount = count[i];
        }
        return retcount;
    }
};