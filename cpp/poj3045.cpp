#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
bool cmp(pll x, pll y)
{
	return x.first + x.second < y.first + y.second;
}

int main()
{
	int n;
	ll w, s;
	scanf("%d", &n);
	vector<pll> v(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end(), cmp);
	ll sum = 0, ans = -0x3f3f3f3f;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, sum - v[i].second);
		sum += v[i].first;
	}
	printf("%lld\n", ans);
	return 0;
}