#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main()
{
	int n;
	ll a, b, x, p, q;
	while (cin >> n >> a >> b)
	{
		map<ll, map<pll, ll>> mp;
		for (int i = 0; i < n; i++)
		{ 
			cin >> x >> p >> q;
			ll tmp = a * p - q;
			pll k(p, q);
			if (!mp.count(tmp)) { mp[tmp] = map<pll, ll>(); mp[tmp][k] = 0; }
			mp[tmp][k]++;
		}
		ll ans = 0;
		for (auto it: mp)
		{
			ll tot = 0;
			for (auto itr: it.second) tot += itr.second;
			for (auto itr: it.second) ans += itr.second * (tot - itr.second);
		}
		cout << ans << endl;
	}
	return 0;
}