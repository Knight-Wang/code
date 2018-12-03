#include <bits/stdc++.h>
using namespace std;

vector<int> v[100005];
vector<int> sum[100005];
vector<int> buf[100005];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m, s, r;
	while (cin >> n >> m)
	{
		for (int i = 0; i <= 100000; i++) v[i].clear();
		for (int i = 0; i <= 100000; i++) sum[i].clear();
		for (int i = 0; i <= 100000; i++) buf[i].clear(); 
		for (int i = 1; i <= n; i++)
		{
			cin >> s >> r;
			v[s].push_back(r);
		}
		int cnt = 0, p = 0;
		for (int i = 1; i <= m; i++)
		{
			if (v[i].size() == 0) continue;
			p = max(p, (int)v[i].size());
			for (int j = 0; j < v[i].size(); j++) buf[cnt].push_back(v[i][j]);
			sort(buf[cnt].begin(), buf[cnt].end(), cmp);
			cnt++;
		}
		for (int i = 0; i < cnt; i++)
		{
			sum[i].push_back(buf[i][0]);
			for (int j = 1; j < buf[i].size(); j++)
			{
				sum[i].push_back(sum[i].back() + buf[i][j]);
			}
		}
		int maxn = 0;
		for (int i = 1; i <= p; i++)
		{
			int tot = 0;
			for (int j = 0; j < cnt; j++)
			{
				if (buf[j].size() >= i && sum[j][i - 1] > 0)
				{
					tot += sum[j][i - 1];
				}
			}
			maxn = max(maxn, tot);
		}
		cout << maxn << endl;
	}
	return 0;
}