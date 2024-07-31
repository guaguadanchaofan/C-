#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0; int ret = 0;
        for (auto x : nums)
        {
            sum += x; //计算当前前缀和
            int r = (sum % k + k) % k;  //计算修正后余数
            if (hash.count(r)) ret += hash[r]; //统计结果
            hash[r]++;
        }
        return ret;
    }
};