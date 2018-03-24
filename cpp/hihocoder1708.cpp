#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, x, y, a, b, c, d;
ll get(ll x, ll y, ll a, ll b)
{
	if (a == 0 && b == 0) return 0;
	else if (a == 0 && b > 0) return (m - y) / b;
	else if (a == 0 && b < 0) return (y - 1) / (-b);
	else if (a > 0 && b == 0) return (n - x) / a;
	else if (a < 0 && b == 0) return (x - 1) / (-a);
	else if (a > 0 && b > 0) return min((n - x) / a, (m - y) / b);
	else if (a > 0 && b < 0) return min((n - x) / a, (y - 1) / (-b));
	else if (a < 0 && b > 0) return min((x - 1) / (-a), (m - y) / b);
	else return min((x - 1) / (-a), (y - 1) / (-b));
}
int main()
{
	cin >> n >> m >> x >> y >> a >> b >> c >> d;
	ll ans = get(x, y, a, b);
	ans += get(x, y, c, d);
	if (!((a == 0 && b == 0) || (c == 0 && d == 0)) && a * d == b * c)
	{
		ll p = 0, q = 0;
		if (a) p = a / __gcd(a, c) * c;
		if (b) q = b / __gcd(b, d) * d;
		ans -= get(x, y, p, q);
	}
	cout << ans + 1 << endl;
	return 0;
}
