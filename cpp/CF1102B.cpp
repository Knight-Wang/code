#include <bits/stdc++.h>
using namespace std;

int a[5005], c[5005], res[5005];
vector<int> v[5005];

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	while (cin >> n >> k)
	{
		memset(c, 0, sizeof c);
		for (int i = 1; i <= 5000; i++) v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			c[a[i]] = res[i] = c[a[i]] + 1;
			v[res[i]].push_back(i);
		}
		if (k > n) { cout << "NO" << endl; continue; }
		int ans = 0;
		for (int i = 1; i <= 5000; i++) ans = max(ans, res[i]);
		if (ans > k) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		if (ans < k)
		{
			int now = ans;
			for (int i = 1; i <= ans; i++)
			{
				for (int j = 1; j < v[i].size(); j++)
				{
					res[v[i][j]] = ++now;
					if (now == k) break;
				}
				if (now == k) break;
			}
		}
		for (int i = 1; i <= n; i++) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}