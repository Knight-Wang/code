#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXM = 500005, MAXN = 50005;
const int INF = 0x3f3f3f3f;
int s[MAXM], t[MAXM], dp[MAXN], tree[MAXN << 2], n, m;
void build(int num, int l, int r)
{
	if (l == r) { tree[num] = dp[l]; return; }
	int m = l + r >> 1;
	build(num << 1, l, m);
	build(num << 1 | 1, m + 1, r);
	tree[num] = min(tree[num << 1], tree[num << 1 | 1]);
}
void update(int num, int l, int r, int x, int dx)
{
	if (l == r) { tree[num] += dx; return; }
	int m = l + r >> 1;
	if (x <= m) update(num << 1, l, m, x, dx);
	else update(num << 1 | 1, m + 1, r, x, dx);
	tree[num] = min(tree[num << 1], tree[num << 1 | 1]);
}
int query(int num, int l, int r, int x, int y)
{
	if (x <= l && y >= r) return tree[num];
	int m = l + r >> 1, ans = INF;
	if (x <= m) ans = min(ans, query(num << 1, l, m, x, y));
	if (y >= m + 1) ans = min(ans, query(num << 1 | 1, m + 1, r, x, y));
	return ans;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d %d", &s[i], &t[i]);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) dp[i] = INF;
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int tmp = min(dp[t[i]], query(1, 1, n, s[i], t[i]) + 1);
		update(1, 1, n, t[i], tmp - dp[t[i]]);
		dp[t[i]] = tmp;
	}
	printf("%d\n", dp[n]);
	return 0;
}