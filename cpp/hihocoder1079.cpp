#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 200005;
int tree[N << 2], lazy[N << 2], a[N];

void init()
{
	memset(tree, 0, sizeof tree);
	memset(lazy, 0, sizeof lazy);
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
	init();
	int n, l, x, y;
	cin >> n >> l;
	vector<pii> q;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		q.push_back(pii(x, y));
		v.push_back(x); v.push_back(y);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	map<int, int> mp;
	for (int i = 0; i < v.size(); i++) mp[v[i]] = 2 * i + 1;
	int ans = 0, m = v.size() * 2;
	for (int i = n - 1; i >= 0; i--)
	{
		int x = mp[q[i].first], y = mp[q[i].second];
		if (query(1, 1, m, x, y) < y - x + 1) ans++;
		update(1, 1, m, x, y, 1);
	}
	cout << ans << endl;
	return 0;
}