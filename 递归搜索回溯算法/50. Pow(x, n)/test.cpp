#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            return 1.0 / Pow(x, -(long long)n);
        }
        else
        {
            return Pow(x, n);
        }
    }

    double Pow(double x, long long  n)
    {
        if (n == 0)
            return 1.0;
        auto tmp = myPow(x, n / 2);
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }
};