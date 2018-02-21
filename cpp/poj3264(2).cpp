#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 50005;
const int INF = 0x3f3f3f3f;
int a[MAXN], minn[MAXN * 4], maxn[MAXN * 4], n, m;

void build(int num, int l, int r)
{
	if (l == r) { maxn[num] = minn[num] = a[l]; return; }
	int m = l + r >> 1;
	build(num * 2, l, m);
	build(num * 2 + 1, m + 1, r);
	maxn[num] = max(maxn[num * 2], maxn[num * 2 + 1]);
	minn[num] = min(minn[num * 2], minn[num * 2 + 1]);
}

int query(int num, int l, int r, int x, int y, int type)
{
	if (x <= l && y >= r) return type ? maxn[num] : minn[num];
	int m = l + r >> 1;
	int ans = type ? -INF : INF;
	if (x <= m) 
	{ 
		int tmp = query(num * 2, l, m, x, y, type); 
		ans = type ? max(ans, tmp) : min(ans, tmp);
	}
	if (y >= m + 1)
	{	
		int tmp = query(num * 2 + 1, m + 1, r, x, y, type);
		ans = type ? max(ans, tmp) : min(ans, tmp);
	}
	return ans;
}

int main()
{
	int l, r;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	for (int i = 0; i < m; i++) 
	{
		scanf("%d %d", &l, &r);
		printf("%d\n", query(1, 1, n, l, r, 1) - query(1, 1, n, l, r, 0));
	}
	return 0;
}