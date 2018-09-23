#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
ll a[MAXN], b[MAXN], bit[2 * MAXN];
int n;
int lowbit(int x)
{
	return x & -x;
}
ll sum(int x)
{
	ll ans = 0;
	while (x)
	{
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}
void add(int i, ll x, int maxn)
{
	while (i <= maxn)
	{
		bit[i] += x;
		i += lowbit(i);
	}
}
int main()
{
	ll t;
	while (cin >> n >> t)
	{
		memset(b, 0, sizeof b);
		memset(bit, 0, sizeof bit);
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i];
			b[i] = b[i - 1] + a[i];
		}
		vector<ll> v;
		for (int i = 0; i <= n; i++)
		{
			v.push_back(b[i]);
			v.push_back(b[i] + t);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		ll ans = 0;
		for (int i = n; i >= 1; i--)
		{
			int pos = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1; 
			add(pos, 1, v.size());
			pos = lower_bound(v.begin(), v.end(), b[i - 1] + t) - v.begin() + 1;
			ans += sum(pos - 1);
		}
		cout << ans << endl;
	}
	return 0;
}