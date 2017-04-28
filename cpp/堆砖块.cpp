#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 500000;
int a[55], dp[2][2 * MAXN + 1], n;

bool check(int x)
{
    return x >= -MAXN && x <= MAXN;
}

int solve()
{
    for (int i = -MAXN; i <= MAXN; i++) dp[n & 1][i + MAXN] = -INF;
    dp[n & 1][MAXN] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = -MAXN; j <= MAXN; j++)
        {
            dp[i & 1][j + MAXN] = dp[(i + 1) & 1][j + MAXN];
            if (check(j - a[i]))
                dp[i & 1][j + MAXN] = 
                max(dp[i & 1][j + MAXN], dp[(i + 1) & 1][j - a[i] + MAXN] + a[i]);
            if (check(j + a[i]))
                dp[i & 1][j + MAXN] = 
                max(dp[i & 1][j + MAXN], dp[(i + 1) & 1][j + a[i] + MAXN]);
        }
    }
    return dp[0][MAXN];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = solve();
    if (x > 0) cout << x << endl;
    else puts("-1");
    return 0;
}