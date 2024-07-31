#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:

    int mySqrt(int x) {
        if (x < 1)
        {
            return 0;
        }
        long long left = 0;
        long long right = x;
        while (left < right)
        {
            long long  mid = left + (right - left + 1) / 2;
            if (mid * mid > x)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        return left;
    }
};