#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int sum = duration;
        for (int i = 0; i < n - 1; i++)
        {
            sum += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return sum;
    }
};