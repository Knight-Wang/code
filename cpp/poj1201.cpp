#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
struct node
{
	int l, r, c;
};
node a[MAXN];
int tree[MAXN * 4], n;
bool vis[MAXN];
bool cmp(const node & a, const node & b)
{
	return a.r < b.r;
}
void update(int num, int l, int r, int x, int dx)
{
	if (l == r) { tree[num] += dx; return; }
	int m = l + r >> 1;
	if (x <= m) update(num << 1, l, m, x, dx);
	else update(num << 1 | 1, m + 1, r, x, dx);
	tree[num] = tree[num << 1] + tree[num << 1 | 1];
}
int query(int num, int l, int r, int x, int y)
{
	if (x <= l && y >= r) return tree[num];
	int m = l + r >> 1;
	int ans = 0;
	if (x <= m) ans += query(num << 1, l, m, x, y);
	if (y >= m + 1) ans += query(num << 1 | 1, m + 1, r, x, y);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r >> a[i].c;
	sort(a, a + n, cmp);
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = query(1, 0, 50000, a[i].l, a[i].r);
		if (cnt < a[i].c)
		{
			int x = a[i].r;
			while (cnt < a[i].c) 
			{
				if (vis[x]) { x--; continue; }
				update(1, 0, 50000, x, 1); 
				vis[x--] = true;
				cnt++;
				tot++;
			}
		}
	}
	cout << tot << endl;
	return 0;
}