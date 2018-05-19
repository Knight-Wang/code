#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 200005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

vector<pll> v;

bool cmp(pll & x, pll & y)
{
	return x.first - x.second > y.first - y.second;
}

int main()
{
	int n, a, b;
	while (cin >> n >> a >> b)
	{	
		v.resize(n);
		ll ans = 0;
		for (int i = 0; i < n; i++) 
		{
			cin >> v[i].first >> v[i].second;
			ans += v[i].second;
		}
		if (!b) { cout << ans << endl; continue; }
		sort(v.begin(), v.end(), cmp);
		int i = 0;
		for ( ; i < v.size(); i++)
		{
			if (v[i].first <= v[i].second) break;
		}
		int pos = min(n, min(i, b));
		ans = 0;
		for (int i = 0; i < pos; i++) ans += v[i].first;
		for (int i = pos; i < n; i++) ans += v[i].second;
		ll maxn = ans;
		for (int i = 0; i < n; i++)
		{
			if (i < pos)
			{
				ll tmp = ans - v[i].first + (v[i].first << a);
				if (tmp > maxn) maxn = tmp;
			}
			else
			{
				ll tmp = ans - v[i].second + (v[i].first << a);
				if (pos && pos == b) tmp += - v[pos - 1].first + v[pos - 1].second;
				if (tmp > maxn) maxn = tmp;
			}
		}
		cout << maxn << endl;
	}
	return 0;
}