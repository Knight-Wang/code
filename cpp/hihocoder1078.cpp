#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int tree[N << 2], lazy[N << 2], a[N], n, q;

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
	if (!lazy[num]) return;
	tree[num << 1] = lazy[num] * cl;
	tree[num << 1 | 1] = lazy[num] * cr;
	lazy[num << 1] = lazy[num];
	lazy[num << 1 | 1] = lazy[num];
	lazy[num] = 0;
}

void update(int num, int l, int r, int x, int y, int p)
{
	if (x <= l && y >= r) { tree[num] = (r - l + 1) * p; lazy[num] = p; return; }
	int m = l + r >> 1;
	pushdown(num, m - l + 1, r - m);
	if (x <= m) update(num << 1, l, m, x, y, p);
	if (y >= m + 1) update(num << 1 | 1, m + 1, r, x, y, p);
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
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	cin >> q;
	int x, y, t, p;
	for (int i = 1; i <= q; i++)
	{
		cin >> t;
		if (t == 0)
		{
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << endl;
		}
		else
		{
			cin >> x >> y >> p;
			update(1, 1, n, x, y, p);
		}
	}
	return 0;
}