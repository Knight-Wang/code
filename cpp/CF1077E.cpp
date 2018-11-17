#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);
	int n, x;
	while (cin >> n)
	{
		map<int, int> mp;
		for (int i = 0; i < n; i++) 
		{
			cin >> x;
			if (!mp.count(x)) mp[x] = 0;
			mp[x]++;
		}
		vector<ll> v;
		for (auto it: mp) v.push_back(it.second);
		sort(v.begin(), v.end());
		ll ans = 0;
		int l = v.size();
		for (int i = 1; i <= min(30, l); i++)
		{
			for (int j = 0; j <= l - i; j++)
			{
				ll minn = INF, bin = 0;
				for (int k = j; k < j + i; k++)
				{
					minn = min(minn, v[k] / (1 << bin));
					bin++;
				}
				ans = max(ans, minn * ((1ll << i) - 1));
			}
		}
		cout << ans << endl;
	}
	return 0;
}