#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int bit[2000005];
int lowbit(int x)
{
    return x & -x;
}
ll sum(int x)
{
    ll ans = 0;
    while (x)
    {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}
void add(int i, ll x, int maxn)
{
    while (i <= maxn)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}
 
int main()
{
    int n;
    while (cin >> n)
    {
        memset(bit, 0, sizeof bit);
        vector<int> v(n, 0x3f3f3f3f);
        vector<bool> ok(n, false);
        for (int i = 0; i < n; i++)
        {
            int l; cin >> l;
            int maxn = 0;
            for (int j = 0; j < l; j++)
            {
                cin >> a[j]; a[j]++;
                if (j && a[j] > a[j - 1]) ok[i] = true;
                maxn = max(maxn, a[j]);
                v[i] = min(v[i], a[j]);
            }
            if (!ok[i]) add(maxn, 1, 1000001);
        }
        ll res = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ok[i]) cnt++;
        }
        for (int i = 0; i < n; i++)
        {
            if (ok[i]) res += n;
            else
            {
                res += sum(1000001) - sum(v[i]);
                res += cnt;
            }
        }
        cout << res << endl;
    }
    return 0;
}