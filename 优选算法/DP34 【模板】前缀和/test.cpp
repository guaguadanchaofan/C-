#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> nums(n + 1);
    vector<long long> dp(n + 1);
    for (long long i = 1; i <= n; i++) {
        cin >> nums[i];
        dp[i] = dp[i - 1] + nums[i];
    }
    long long a, b;
    while (cin >> a >> b)
    {
        cout << dp[b] - dp[a - 1] << endl;
    }

}

// 64 Î»Êä³öÇëÓÃ printf("%lld")