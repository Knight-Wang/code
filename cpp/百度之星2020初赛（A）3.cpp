#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main()
{
    dp[1][1] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int tmp = 0;
            if (__gcd(i, j) == 1) tmp++;
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + tmp;
        }
    }
    int t, x, y; scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &x, &y);
        int a = min(x, y);
        int b = max(x, y);
        printf("%d\n", dp[b][a]);
    }
    return 0;
}