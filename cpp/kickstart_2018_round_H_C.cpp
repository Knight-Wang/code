#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 200000;
ll f[MAXN + 5], inv[MAXN + 5];
ll pow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return res;
}

void init()
{
	f[0] = 1;
	for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i % MOD;
	inv[MAXN] = pow(f[MAXN], MOD - 2);
	for (int i = MAXN - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll C(int a, int b)
{
	return f[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main()
{
	init();
	int T, n, m;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> n >> m;
		ll ans = 0, s = 1, bin = 1;
		for (int i = 0; i <= m; i++)
		{
			ans = (ans + s * C(m, i) * bin % MOD * f[2 * n - i] % MOD) % MOD;
			s *= -1;
			bin = bin * 2 % MOD;
		}
		cout << "Case #" << i << ": " << (ans + MOD) % MOD << endl;
	}
	return 0;
}