#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
int G[MAXN][MAXN], d[MAXN];
bool in[MAXN];
int n, p, k;
int spfa(int s, int t, int x)
{
	memset(in, false, sizeof in);
	memset(d, 0x3f, sizeof d);
	queue<int> q;
	d[s] = 0;
	q.push(s);
	in[s] = true;
	while (!q.empty())
	{
		int tmp = q.front(); q.pop();
		in[tmp] = false;
		for (int i = 1; i <= n; i++)
		{
			int w = INF; 
			if (G[tmp][i] != INF) w = G[tmp][i] > x ? 1 : 0;  
			if (d[tmp] + w < d[i])
			{
				d[i] = d[tmp] + w;
				if (!in[i]) { in[i] = true; q.push(i); }
			}
		}
	}
	return d[t];
}
bool check(int x)
{
	int cnt = spfa(1, n, x);
	return cnt <= k;
}
int main()
{
	scanf("%d %d %d", &n, &p, &k);
	int a, b, w, maxw = -INF;
	memset(G, 0x3f, sizeof G);
	for (int i = 0; i < p; i++) 
	{	
		scanf("%d %d %d", &a, &b, &w);
		G[a][b] = G[b][a] = w;
		maxw = max(maxw, w);
	}
	int l = 0, r = maxw, ans = INF;
	while (l <= r)
	{
		int m = l + r >> 1;
		if (check(m)) { ans = m; r = m - 1; }
		else l = m + 1;
	}
	if (ans == INF) puts("-1");
	else printf("%d\n", ans);
	return 0;
}