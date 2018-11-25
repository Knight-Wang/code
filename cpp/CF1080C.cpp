#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> cal(ll x1, ll y1, ll x2, ll y2)
{
	ll x = (x2 - x1 + 1), y = (y2 - y1 + 1);
	pair<ll, ll> ans(x * y / 2, x * y / 2);
	if (x * y % 2 == 1)
	{
		if ((x2 % 2 == 0 && y2 % 2 == 0) || (x2 % 2 == 1) && (y2 % 2 == 1))
			ans.first++;
		else ans.second++;
	}
	return ans;
}

int main()
{
	int t;
	ll n, m, x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		ll w = n * m / 2, b = n * m / 2;
		if (n * m % 2 == 1) w++;
		pair<ll, ll> tmp = cal(x1, y1, x2, y2);
		w += tmp.second;
		b -= tmp.second;
		tmp = cal(x3, y3, x4, y4);
		w -= tmp.first;
		b += tmp.first;
		pair<ll, ll> x(-1, -1), y(-1, -1);
		if (y1 >= y3 && y2 <= y4) { y.first = y1; y.second = y2; }
		else if (y3 >= y1 && y3 <= y2) { y.first = y3; y.second = min(y4, y2); }
		else if (y4 >= y1 && y4 <= y2) { y.first = max(y1, y3); y.second = y4; }
		if (x1 >= x3 && x2 <= x4) { x.first = x1; x.second = x2; }
		else if (x3 >= x1 && x3 <= x2) { x.first = x3; x.second = min(x4, x2); }
		else if (x4 >= x1 && x4 <= x2) { x.first = max(x1, x3); x.second = x4; }
		if (x.first != -1 && y.first != -1)
		{
			tmp = cal(x.first, y.first, x.second, y.second);
			w -= tmp.second;
			b += tmp.second;
		}
		cout << w << " " << b << endl;
	}
	return 0;
}