#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int a[N], tree[N * 4], n;

void build(int num, int l, int r)
{
	if (l == r) { tree[num] = a[l]; return; }
	int m = l + r >> 1;
	build(num * 2, l, m);
	build(num * 2 + 1, m + 1, r);
	tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

void update(int num, int l, int r, int x, int dx)
{
	if (l == r) { tree[num] += dx; return; }
	int m = l + r >> 1;
	if (x <= m) update(num * 2, l, m, x, dx);
	else update(num * 2 + 1, m + 1, r, x, dx);
	tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

int query(int num, int l, int r, int x, int y)
{
	if (x <= l && y >= r) return tree[num];
	int m = l + r >> 1, ans = 0;
	if (x <= m) ans += query(num * 2, l, m, x, y);
	if (y >= m + 1) ans += query(num * 2 + 1, m + 1, r, x, y);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int T, Kase = 1;
	cin >> T;
	while (T--)
	{
		cout << "Case " << Kase++ << ":" << endl;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		build(1, 1, n);
		string tmp; int a, b;
		while (cin >> tmp, tmp[0] != 'E')
		{
			if (tmp[0] == 'Q') { cin >> a >> b; cout << query(1, 1, n, a, b) << endl; }
			else if (tmp[0] == 'A') { cin >> a >> b; update(1, 1, n, a, b); }
			else { cin >> a >> b; update(1, 1, n, a, -b); } 
		}
	}
	return 0;
}