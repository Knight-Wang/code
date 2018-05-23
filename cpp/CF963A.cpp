#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 9;
ll mypow(ll x, ll n)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return ans;
}
ll inv(ll x)
{
	return mypow(x, MOD - 2);
}
ll cal(ll x, ll a, ll b, ll n, ll k)
{
	ll q = mypow(b, k) * inv(mypow(a, k)) % MOD;
	if (q == 1) return x * n % MOD;
	return x * (mypow(q, n) - 1 + MOD) % MOD * inv(q - 1) % MOD;
}
int main()
{
	ll n, a, b, k, x, q, l;
	string s;
	while (cin >> n >> a >> b >> k >> s)
	{
		ll ans = 0, l = (n + 1) / k;
		for (int i = 0; i < k; i++)
		{
			x = mypow(a, n - i) * mypow(b, i) % MOD;
			ll tmp = (s[i] == '+' ? 1 : -1) * cal(x, a, b, l, k);
			ans = (ans + tmp) % MOD;
			ans = (ans + MOD) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}