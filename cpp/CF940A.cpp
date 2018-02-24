#include <bits/stdc++.h>
using namespace std;
int a[105], n, d;
int main()
{
	int tmp;
	while (cin >> n >> d)
	{
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++) { cin >> tmp; a[tmp]++; }
		vector<int> v;
		for (int i = 1; i <= 100; i++) if (a[i]) v.push_back(i);
		int maxn = -1;
		for (int i = 0; i < v.size(); i++)
		{
			int t = v[i] + d;
			int ans = 0;
			for (int j = i; j < v.size() && v[j] <= t; j++)
			{
				ans += a[v[j]];
			}
			maxn = max(maxn, ans);
		}
		cout << n - maxn << endl;
	}
	return 0;
}