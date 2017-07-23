#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll man[1005], key[2005];
ll cal(ll m, ll k, ll p)
{
	if ((k >= m && k <= p) || (k <= m && k >= p)) return abs(m - p);
	return abs(m - k) + abs(k - p);
}
int main()
{
	ll n, k, p, ans = INF;
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) cin >> man[i];
	for (int i = 0; i < k; i++) cin >> key[i];
	sort(man, man + n); sort(key, key + k);
	for (int i = 0; i <= k - n; i++)
	{
		ll maxn = 0;
		for (int j = 0; j < n; j++)
		{
			maxn = max(maxn, cal(man[j], key[j + i], p));
		}
		ans = min(ans, maxn);
	}
	cout << ans << endl;
	return 0;
}