#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int tree[N << 2], lazy_set[N << 2], lazy_add[N << 2], a[N], n, q;

void build(int num, int l, int r)
{
	if (l == r) { tree[num] = a[l]; return; }
	int m = l + r >> 1;
	build(num << 1, l, m);
	build(num << 1 | 1, m + 1, r);
	tree[num] = tree[num << 1] + tree[num << 1 | 1];
}

void pushdown(int num, int cl, int cr)
{
	if (lazy_set[num])
	{
		tree[num << 1] = lazy_set[num] * cl;
		tree[num << 1 | 1] = lazy_set[num] * cr;
		lazy_set[num << 1] = lazy_set[num];
		lazy_set[num << 1 | 1] = lazy_set[num];
		lazy_add[num << 1] = 0;
		lazy_add[num << 1 | 1] = 0;
		lazy_set[num] = 0;
	}
	if (lazy_add[num])
	{
		tree[num << 1] += lazy_add[num] * cl;
		tree[num << 1 | 1] += lazy_add[num] * cr;
		lazy_add[num << 1] += lazy_add[num];
		lazy_add[num << 1 | 1] += lazy_add[num];
		lazy_add[num] = 0;		
	}
}

void update(int num, int l, int r, int x, int y, int p, int t)
{
	if (x <= l && y >= r)
	{
		if (t == 0)
		{
			tree[num] += (r - l + 1) * p;
			lazy_add[num] += p;
		}
		else
		{
			tree[num] = (r - l + 1) * p; 
			lazy_set[num] = p;
			lazy_add[num] = 0;
		}
		return;
	}
	int m = l + r >> 1;
	pushdown(num, m - l + 1, r - m);
	if (x <= m) update(num << 1, l, m, x, y, p, t);
	if (y >= m + 1) update(num << 1 | 1, m + 1, r, x, y, p, t);
	tree[num] = tree[num << 1] + tree[num << 1 | 1];
}

int query(int num, int l, int r, int x, int y)
{
	if (x <= l && y >= r) return tree[num];
	int m = l + r >> 1;
	pushdown(num, m - l + 1, r - m);
	int ans = 0;
	if (x <= m) ans += query(num << 1, l, m, x, y);
	if (y >= m + 1) ans += query(num << 1 | 1, m + 1, r, x, y);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n + 1; i++) cin >> a[i];
	build(1, 1, n + 1);
	int x, y, t, p;
	for (int i = 1; i <= q; i++)
	{
		cin >> t >> x >> y >> p;
		x++; y++;
		update(1, 1, n + 1, x, y, p, t);
		cout << query(1, 1, n + 1, 1, n + 1) << endl;
	}
	return 0;
}