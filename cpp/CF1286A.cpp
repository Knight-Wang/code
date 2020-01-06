#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[105], dp[105][105][105][2], n;
int dfs(int cur, int o, int e, int last)
{
    if (cur == n) return 0;
    if (dp[cur][o][e][last] != -1) return dp[cur][o][e][last];
    int res = INF;
    if (a[cur] == 0)
    {
        if (o) res = min(res, dfs(cur + 1, o - 1, e, 1) + (last != 1));
        if (e) res = min(res, dfs(cur + 1, o, e - 1, 0) + (last != 0));
    }
    else
    {
        res = dfs(cur + 1, o, e, a[cur] & 1) + ((a[cur] & 1) != last);
    }
    return dp[cur][o][e][last] = res;
}
int main()
{
    while (cin >> n)
    {
        memset(dp, -1, sizeof dp);
        int o = n / 2, e = n / 2;
        if (n & 1) o++;
        int oo = 0, ee = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (!a[i]) continue;
            if (a[i] & 1) oo++;
            else ee++;
        }
        if (n == 1) { cout << 0 << endl; continue; }
        o -= oo; e -= ee;
        int res = INF;
        if (a[0] == 0) res = min(dfs(1, o - 1, e, 1), dfs(1, o, e - 1, 0));
        else res = dfs(1, o, e, a[0] & 1);
        cout << res << endl;
    }
    return 0;
}