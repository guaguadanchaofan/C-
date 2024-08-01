#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0)
        {
            int i = a ^ b;
            int j = (a & b) << 1;
            a = i;
            b = j;
        }

        return a;
    }
};