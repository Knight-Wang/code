#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 300005;
const int INF = 0x3f3f3f3f;
int a[MAXN], n;
bool check(int x)
{
    ll low = 0, up = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < x) low += x - a[i];
        else if (a[i] % 2 == x % 2) up += a[i] - x;
        else up += (a[i] - x) / 2 * 2;
    }
    return low * 2 <= up;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int l = 0, r = 100000000, ans = -INF;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(m))
            {
                ans = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        cout << (ans < 0 ? -1 : ans) << endl;
    }
    return 0;
}