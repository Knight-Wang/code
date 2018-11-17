#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool check(vector<int>& v, int x, int k)
{
	int p = lower_bound(v.begin(), v.end(), x) - v.begin();
	int l = v.size();
	if (l - p >= k) return true;
	int num = 0;
	for (int i = p; i < l; i++) num += v[i] / x;
	return num >= k;
}
int main()
{
	int n, k, x;
	while (cin >> n >> k)
	{
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) 
		{
			cin >> x;
			a[x]++;
		}
		vector<pair<int, int>> v;
		for (int i = 1; i <= 200000; i++)
		{
			if (a[i]) v.push_back(make_pair(a[i], i));
		}
		sort(v.begin(), v.end());
		vector<int> v2;
		for (auto it: v) v2.push_back(it.first);
		int l = 1, r = n, ans = 1;
		while (l <= r)
		{
			int m = l + r >> 1;
			if (check(v2, m, k))
			{
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		int cnt = 0, i = lower_bound(v2.begin(), v2.end(), ans) - v2.begin();
		for ( ; i < v.size(); i++)
		{
			while (v[i].first >= ans && cnt < k)
			{
				cout << v[i].second << " ";
				v[i].first -= ans;
				cnt++;
			}
		}
		cout << endl;
	}
	return 0;
}