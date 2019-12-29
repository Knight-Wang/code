#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
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
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        cout << my_pow(my_pow(2, m) - 1, n) << endl;
    }
    return 0;
}