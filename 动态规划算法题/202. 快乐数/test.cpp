#define  _CRT_SECURE_NO_WARNINGS
202. ¿ìÀÖÊı
class Solution {
public:
    int bitsum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += pow(n % 10, 2);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = bitsum(n);
        while (slow != fast)
        {
            slow = bitsum(slow);
            fast = bitsum(bitsum(fast));
        }
        return slow == 1;
    }
};