#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
ll n, x, y, z;
bool check(ll m)
{
	ll tmp = m * x - n * z;
	if (tmp <= 0) return true;
	else if (y > z && tmp <= m * (y - z)) return true;
	return false;
}
int main()
{
	while (cin >> n >> x >> y >> z)
	{
		ll l = 0, r = INF, ans = -1;
		while (l <= r)
		{
			ll m = l + r >> 1;
			if (check(m))
			{
				ans = m; l = m + 1;
			}
			else r = m - 1;
		}
		cout << ans << endl;
	}
	return 0;
}