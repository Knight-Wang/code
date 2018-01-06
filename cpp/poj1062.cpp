#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int times[MAXN], d[MAXN], level[MAXN];
bool in[MAXN];
int m, n;
struct edge
{
	int to, cost;
};
vector<edge> G[MAXN];
bool spfa(int s, int minL, int maxL)
{
	queue<int> q;
	for (int i = 0; i <= n; i++)
	{
		in[i] = false;
		d[i] = INF;
		times[i] = 0;	
	}
	in[s] = true; d[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int tmp = q.front(); q.pop(); in[tmp] = false;
		for (int i = 0; i < G[tmp].size(); i++)
		{
			edge & e = G[tmp][i];
			if (level[e.to] < minL || level[e.to] > maxL) continue;
			if (d[tmp] + e.cost < d[e.to])
			{
				d[e.to] = d[tmp] + e.cost;
				times[e.to]++;
				if (times[e.to] == n) return false;
				if (!in[e.to])
				{
					in[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
	return true;
}
int main()
{
	int p, l, x, t, v;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p >> l >> x;
		level[i] = l;
		G[0].push_back(edge{i, p});
		for (int j = 0; j < x; j++)
		{
			cin >> t >> v;
			G[t].push_back(edge{i, v});
		}
	}
	int ans = INF;
	for (int i = level[1] - m; i <= level[1]; i++)
	{
		spfa(0, i, i + m); 
		ans = min(ans, d[1]); 
	}
	cout << ans << endl;
	return 0;
}