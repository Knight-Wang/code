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
	ll a, b, c, k;
	while (cin >> a >> b >> c >> k, a || b || c || k)
	{
		ll tmp = 1;
		tmp <<= k;
		ll d, x, y;
		d = extgcd(c, tmp, x, y);
		if ((b - a) % d) puts("FOREVER");
		else
		{
			ll mod = abs(tmp / d);
			x = (x * (b - a) / d % mod + mod) % mod;
			cout << x << endl;
		}
	}
	return 0;
}