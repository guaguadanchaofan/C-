#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> dq;
        for (auto e : nums)
        {
            dq.push(e);
        }
        while (k - 1 > 0)
        {
            k--;
            dq.pop();
        }
        int max = dq.top();
        return max;
    }
};