#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        //unordered_map<int,int> hash;
        int hash[100001] = { 0 };
        int ret = 0;
        for (int left = 0, right = 0, kinds = 0; right < n; right++)
        {
            if (hash[fruits[right]] == 0)kinds++;
            hash[fruits[right]]++;
            while (kinds > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)
                {
                    kinds--;
                }
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};