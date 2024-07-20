#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hash;
        hash[arr[0]] = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]] = hash[arr[i] - difference] + 1;
            ret = max(ret, hash[arr[i]]);
        }
        return ret;
    }
};