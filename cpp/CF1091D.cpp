#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int N = 1000000;

ll a[N + 5], f[N + 5];

ll pow(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
    	if (n & 1) res = res * x % MOD;
    	x = x * x % MOD;
    	n >>= 1;
	}
	return res;
}

ll inv(ll x)
{
	return pow(x, MOD - 2);
}

int main()
{
	ll n;
	f[0] = 1;
	for (int i = 1; i <= N; i++) f[i] = f[i - 1] * (ll)i % MOD;
	a[N] = inv(f[N]);
	for (int i = N - 1; i >= 0; i--) a[i] = a[i + 1] * (i + 1) % MOD;
	while (cin >> n)
	{
		if (n <= 2) { cout << n << endl; continue; }
		ll ans = (f[n] * n - f[n] * inv(2) * 3) % MOD;
		for (int i = 3; i <= n - 1; i++) ans = (ans - f[n] * a[i] % MOD) % MOD;
		cout << (ans + MOD) % MOD << endl;
	}
	return 0;
}