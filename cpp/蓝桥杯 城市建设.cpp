#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;
const int INF = 0x3f3f3f3f;
struct node
{
	int x, y, c;
};
node a[MAXN + MAXM];
int par[MAXN];
void init(int n)
{
	for (int i = 1; i <= n; i++) par[i] = i;
}
int find(int x)
{
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
void uni(int x, int y)
{
	x = find(x); y = find(y);
	if (x != y) par[x] = y;
}
bool cmp(node & a, node & b)
{
	return a.c < b.c;
}
int kru(int n, int m)
{
	init(n);
	sort(a + 1, a + m + 1, cmp);
	int cost = 0, cnt = n;
	for (int i = 1; i <= m; i++)
	{
		if (!same(a[i].x, a[i].y))
		{
			uni(a[i].x, a[i].y);
			cnt--;
			cost += a[i].c;
		}
		else if (a[i].c < 0) cost += a[i].c;
	}
	return cnt == 1 ? cost : INF;
}
int main()
{
	int n, m, w;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].x >> a[i].y >> a[i].c;
	int cost = kru(n, m);
	int now = m + 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> w;
		if (w == -1) continue;
		a[now].x = i; a[now].y = n + 1; a[now++].c = w;
	}
	int cost1 = kru(n + 1, now - 1);
	cout << min(cost, cost1) << endl;
	return 0;
}