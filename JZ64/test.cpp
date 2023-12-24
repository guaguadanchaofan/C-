#define  _CRT_SECURE_NO_WARNINGS
#include <new>
class sum
{
public:
    sum()
    {
        _sum += _i;
        _i++;
    }
    static void init()
    {
        _i = 1;
        _sum = 0;
    }
    static int getsum()
    {
        return _sum;
    }
private:
    static int _i;
    static int _sum;
};

int sum::_i = 1;
int sum::_sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        sum::init();
        sum* p = new sum[n];
        return sum::getsum();
    }
};