#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;
int par[MAXN], n, m;
void init(int n) 
{ 
	for (int i = 1; i <= n; i++) par[i] = i; 
}
int find(int x) 
{ 
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void uni(int x, int y)
{
	x = find(x); y = find(y);
	if (x != y) par[x] = y;
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
struct node
{
	int x, y, t;
};
node a[MAXM];
bool cmp(node & a, node & b) { return a.t > b.t; }
int main()
{
	scanf("%d %d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++) scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].t);
	sort(a, a + m, cmp); 
	int cnt = 0, last = -1; 
	for (int i = 0; i < m; i++) 
	{
		if (!same(a[i].x, a[i].y) && a[i].t != last)
		{
			cnt++;
			last = a[i].t;
		}
		uni(a[i].x, a[i].y);
	}
	printf("%d\n", cnt);
	return 0;
}