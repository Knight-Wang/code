#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int get_pow(int x)
{
	int ans = 0;
	while (x)
	{
		x /= 10; ans++;
	}
	return ans;
}
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		map<int, map<int, multiset<int>>> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			int p = get_pow(a[i]), r = a[i] % k;
			if (!mp.count(r)) mp[r] = map<int, multiset<int>>();
			if (!mp[r].count(p)) mp[r][p] = multiset<int>();
			mp[r][p].insert(a[i]);
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ll p = 10;
			for (int j = 1; j <= 10; j++)
			{
				int t = (k - (a[i] % k) * (p % k) % k) % k;
				if (mp.count(t) && mp[t].count(j))
				{
					ans += mp[t][j].size();
					if (mp[t][j].count(a[i]))
						ans--;
				}
				p *= 10;
			}
		}
		cout << ans << endl;
	}
	return 0;
}