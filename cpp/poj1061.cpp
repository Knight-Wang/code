#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll abs(ll x)
{
	return x < 0 ? -x : x;
}

ll extgcd(ll a, ll b, ll & x, ll & y)
{
	int d = a;
	if (!b)
	{
		x = 1; y = 0;
	}
	else
	{
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return d;
}

int main()
{
	ll x, y, m, n, L;
	cin >> x >> y >> m >> n >> L;
	ll ans, p, q;
	ans = extgcd((m - n), L, p, q);
	if ((y - x) % ans) puts("Impossible");
	else
	{
		ll mod = abs(L / ans);
		p = (p * (y - x) / ans % mod + mod) % mod;
		cout << p << endl;
	}
	return 0;
}