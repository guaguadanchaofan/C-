#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int tribonacci(int n) {
        //常规解法
        //1.创建dp表
        //2.初始化
        //3.填表
        //4.返回值

        //version 1
        //vector<int> v(n+1);
        //if(n==0)
        //{
        //    return 0;
        //}
        //if(n==1||n==2)
        //{
        //    return 1;
        //}
        //v[0]=0;
        //v[1]=v[2]=1;
        //for(int i = 3;i< = n; i++)
        //{
        //    v[i]=v[i-1]+v[i-2]+v[i-3];
        //}
        //return v[n];

        //version 2

        int a, b, c, d;
        a = 0;
        b = c = 1;
        d = 0;
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        while (n - 2)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
            n--;
        }
        return d;
    }
};