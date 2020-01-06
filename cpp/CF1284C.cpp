#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[250005];
int main()
{
    ll n, m;
    while (cin >> n >> m)
    {
        f[0] = 1;
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % m;
        ll res = n * f[n] % m;
        for (int i = 2; i <= n; i++)
        {
            res = (res + f[i] * (n - i + 1) % m * f[n - i + 1] % m) % m;
        }
        cout << res << endl;
    }
    return 0;
}