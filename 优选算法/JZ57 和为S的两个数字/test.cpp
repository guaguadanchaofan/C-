#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int n = array.size();
        int left = 0;
        int right = n - 1;
        vector<int> ret;
        while (left < right)
        {
            if (array[left] + array[right] > sum)
            {
                right--;
            }
            else if (array[left] + array[right] == sum)
            {
                ret.push_back(array[left]);
                ret.push_back(array[right]);
                break;
            }
            else if (array[left] + array[right] < sum)
            {
                left++;
            }
        }
        return ret;
    }
};