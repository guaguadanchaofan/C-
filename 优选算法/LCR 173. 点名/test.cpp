#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0;
        int right = records.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (records[mid] == mid)
            {
                left = mid + 1;
            }
            else if (records[mid] > mid)
            {
                right = mid;
            }
        }
        return records[left] == left ? left + 1 : left;
    }
};