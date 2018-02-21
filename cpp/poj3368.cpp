#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int a[MAXN], tree[MAXN * 4], n, m, sum[MAXN];

void build(int num, int l, int r)
{
	if (l == r) { tree[num] = a[l]; return; }
	int m = l + r >> 1;
	build(num * 2, l, m);
	build(num * 2 + 1, m + 1, r);
	tree[num] = max(tree[num * 2], tree[num * 2 + 1]);
}

int query(int num, int l, int r, int x, int y)
{
	if (x <= l && y >= r) return tree[num];
	int ans = -INF, m = l + r >> 1;
	if (x <= m) ans = max(ans, query(num * 2, l, m, x, y));
	if (y >= m + 1) ans = max(ans, query(num * 2 + 1, m + 1, r, x, y));
	return ans;
}

int main()
{
	while (scanf("%d", &n), n)
	{
		memset(a, 0, sizeof a);
		memset(sum, 0, sizeof sum);
		scanf("%d", &m);
		int last = -INF, tmp, now = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &tmp);
			if (tmp == last) a[now]++;
			else last = tmp, a[++now]++;
		}
		build(1, 1, now);
		for (int i = 1; i <= now; i++) sum[i] = sum[i - 1] + a[i];
		int l, r;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &l, &r);
			int ls = lower_bound(sum, sum + now + 1, l) - sum;
			int rs = lower_bound(sum, sum + now + 1, r) - sum;
			int ans = -1;
			if (ls == rs) ans = r - l + 1;
			else 
			{
				ans = max(sum[ls] - l + 1, r - sum[rs - 1]);
				if (rs - ls > 1) ans = max(ans, query(1, 1, now, ls + 1, rs - 1));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}