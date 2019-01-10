#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

int n, a[200005], l[200005], r[200005];

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n)
	{
		memset(l, 0, sizeof l); memset(r, 0, sizeof r);
		int cnt = 0;
		map<int, int> mp;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i]; if (!mp.count(a[i])) mp[a[i]] = ++cnt;
		}
		for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
		for (int i = 1; i <= n; i++) r[a[i]] = i;
		for (int i = n; i >= 1; i--) l[a[i]] = i;
		vector<pair<int, int>> v;
		for (int i = 1; i <= n; i++)
		{
			if (l[i]) v.push_back(make_pair(l[i], r[i]));
		}
		sort(v.begin(), v.end());
		ll ans = 1;
		int now = v[0].second;
		for (int i = 1; i < v.size(); i++)
		{
			if (now > v[i].second) continue;
			if (v[i].first > now) ans = ans * 2 % MOD;
			now = v[i].second;
		}
		cout << ans << endl;
	}
	return 0;
}