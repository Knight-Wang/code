#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
vector<int> v[1000005];
int c[1000005];
ll my_pow(ll a, int n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
ll inv(ll x)
{
    return my_pow(x, MOD - 2);
}
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) { v[i].clear(); c[i] = 0; }
        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int x; cin >> x;
                v[i].push_back(x);
                c[x]++;
            }
        }
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                res = (res + inv(n) * inv(v[i].size()) % MOD * c[v[i][j]] % MOD * inv(n) % MOD) % MOD;
            }
        }
        cout << res << endl;
    }
    return 0;
}