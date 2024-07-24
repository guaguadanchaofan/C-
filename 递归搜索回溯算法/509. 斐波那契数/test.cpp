#define  _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    //int memory[31];
    int fib(int n) {
        //memset(memory,-1,sizeof(memory));
        vector<int> dp(n + 1);
        if (n == 0 || n == 1)
        {
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        //return dfs(n);
    }
    // int dfs(int n)
    // {
    //     if(memory[n]!= -1)
    //     {
    //         return memory[n];
    //     }
    //     if(n==0||n==1)
    //     {
    //         memory[n] = n;
    //         return n;
    //     }
    //     memory[n] = dfs(n-1)+dfs(n-2);
    //     return memory[n];
    // }
};