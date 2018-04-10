#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll MAXN = 100005;
ll x[MAXN], y[MAXN], ok[MAXN], n;
bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}
bool judge(ll a, ll b)
{
	for (ll i = 0; i < n; i++) ok[i] = false;
	for (ll i = 0; i < n; i++) if (check(x[a], y[a], x[b], y[b], x[i], y[i])) ok[i] = true;
	vector<pll> v;
	for (ll i = 0; i < n; i++)
	{
		if (i == a || i == b) continue;
		if (!ok[i]) v.push_back(pll(x[i], y[i])); 
	}
	if (v.size() < 3) return true;
	bool flg = true;
	for (ll i = 2; i < v.size(); i++)
	{
		if (!check(v[0].first, v[0].second, v[1].first, v[1].second, v[i].first, v[i].second))
		{
			flg = false; break;
		}
	}
	return flg;
}
int main()
{
	while (cin >> n)
	{
		for (ll i = 0; i < n; i++) cin >> x[i] >> y[i];
		if (!judge(0, 1) && !judge(0, 2) && !judge(1, 2)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}