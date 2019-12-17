#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
const ll MOD = 1e9 + 7;
ll a[N];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll res = 0;
        for (int i = 0; i < 60; i++)
        {
            ll w = 1ll << i;
            ll cnt0 = 0, cnt1 = 0;
            for (int j = 1; j <= n; j++)
            {
                if (1ll << i & a[j]) cnt1++;
                else cnt0++;
            }
            res = (res + w % MOD * cnt0 % MOD * cnt1 % MOD) % MOD;
        }
        cout << res << endl;
    }
    return 0;
}