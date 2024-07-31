#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0; int ret = 0;
        for (auto x : nums)
        {
            sum += x; //���㵱ǰǰ׺��
            int r = (sum % k + k) % k;  //��������������
            if (hash.count(r)) ret += hash[r]; //ͳ�ƽ��
            hash[r]++;
        }
        return ret;
    }
};