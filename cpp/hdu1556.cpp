#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int tree[N * 4], lazy[N * 4], a[N];
int n;

void build()
{
	memset(tree, 0, sizeof tree);
	memset(lazy, 0, sizeof lazy);
}

void pushdown(int num)
{
	if (!lazy[num]) return;
	tree[num * 2] += lazy[num];
	tree[num * 2 + 1] += lazy[num];
	lazy[num * 2] += lazy[num];
	lazy[num * 2 + 1] += lazy[num];
	lazy[num] = 0;
}

void update(int num, int l, int r, int x, int y, int dx)
{
	if (x <= l && y >= r) { tree[num] += dx; lazy[num] += dx; return; }
	pushdown(num);
	int m = l + r >> 1;
	if (x <= m) update(num * 2, l, m, x, y, dx);
	if (y >= m + 1) update(num * 2 + 1, m + 1, r, x, y, dx);
	tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

int query(int num, int l, int r, int x, int y)
{
	if (x <= l && y >= r) return tree[num];
	pushdown(num);
	int m = l + r >> 1, ans = 0;
	if (x <= m) ans += query(num * 2, l, m, x, y);
	if (y >= m + 1) ans += query(num * 2 + 1, m + 1, r, x, y);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n, n)
	{
		build();
		int a, b;
		for (int i = 0; i < n; i++) { cin >> a >> b; update(1, 1, n, a, b, 1); }
		for (int i = 1; i <= n; i++) 
		{	
			cout << query(1, 1, n, i, i);
			if (i != n) cout << " ";
		}
		cout << endl;
	}
	return 0;
}