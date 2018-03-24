#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int a[MAXN], tree[MAXN * 4], n, m, sum[MAXN];
vector<int> v(1, 0);

void build(int num, int l, int r)
{
    if (l == r) { tree[num] = v[l]; return; }
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
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	a[n] = INF;
	int cnt = 2;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - a[i - 1] != a[i + 1] - a[i]) { v.push_back(cnt - 1); cnt = 2; }
		else cnt++;
	}
	int tot = v.size() - 1;
    build(1, 1, tot);
    for (int i = 1; i <= tot; i++) sum[i] = sum[i - 1] + v[i];
    int l, r;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &l, &r);
        if (n == 1) { puts("1"); continue; }
		int ls = lower_bound(sum + 1, sum + tot + 1, l == n ? l - 1 : l) - sum;
        int rs = lower_bound(sum + 1, sum + tot + 1, r == n ? r - 1 : r) - sum;
        int ans = -1;
        if (ls == rs) ans = r - l + 1;
        else
        {   
        	ans = max(sum[ls] - l + 2, r - sum[rs - 1]);
	        if (rs - ls > 1) ans = max(ans, query(1, 1, tot, ls + 1, rs - 1) + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
