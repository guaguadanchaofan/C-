#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0; int ret = 0;
        for (auto x : nums)
        {
            sum += x;
            if (hash.count(sum - k))ret += hash[sum - k];
            hash[sum]++;
        }
        return ret;
    }
};