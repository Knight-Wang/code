#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
const ll MAXN = 200005, INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<ll, ll> P;
vector<P> L[MAXN], R[MAXN];
ll a[MAXN];

int main()
{
	ll n, x, l, r, c;
	scanf("%I64d %I64d", &n, &x);
	fill(a, a + MAXN, INF);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d %I64d %I64d", &l, &r, &c);
		L[l].push_back({r - l + 1, c});
		R[r].push_back({r - l + 1, c});
	}
	ll ans = INF;
	for (int i = 1; i < MAXN; i++)
	{
		for (auto it : L[i])
		{
			if (it.first >= x) continue;
			ans = min(ans, a[x - it.first] + it.second);
		}
		for (auto it : R[i])
			a[it.first] = min(a[it.first], it.second);
	}
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}