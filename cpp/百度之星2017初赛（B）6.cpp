#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 0x3f3f3f3f;

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		vector<pair<int, int>> v;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			v.push_back(pair<int, int>(x, y));
		}
		sort(v.begin(), v.end());
		vector<pair<int, int>> res;
		res.push_back(v[0]);
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].first > res.back().second + 1) res.push_back(v[i]);
			else res.back().second = max(res.back().second, v[i].second);
		}
		vector<ll> sum(res.size() - 1);
		for (int i = 0; i < res.size() - 1; i++)
			sum[i] = (ll)res[i + 1].first - 1 - res[i].second;
		sum.push_back(INF);
		for (int i = 1; i < sum.size(); i++)
			sum[i] += sum[i - 1];
		ll maxn = 0;
		for (int i = 0; i < sum.size(); i++)
		{
			ll tmp = (i == 0 ? 0 : sum[i - 1]);
			int pos = upper_bound(sum.begin() + i, sum.end(), m + tmp) - sum.begin();
			ll tmp2 = (pos == i ? m : m - (sum[pos - 1] - tmp));
			maxn = max(maxn, res[pos].second - res[i].first + 1 + tmp2);
		}
		printf("%lld\n", maxn);
	}
	return 0;
}