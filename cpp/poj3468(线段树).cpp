#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100005;
ll tree[N * 4], lazy[N * 4], a[N];
int n, m;

void build(int num, int l, int r)
{
    if (l == r) { tree[num] = a[l]; return; }
    int m = l + r >> 1;
    build(num * 2, l, m);
    build(num * 2 + 1, m + 1, r);
    tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

void pushdown(int num, int cl, int cr)
{
    if (!lazy[num]) return;
    tree[num * 2] += lazy[num] * cl;
    tree[num * 2 + 1] += lazy[num] * cr;
    lazy[num * 2] += lazy[num];
    lazy[num * 2 + 1] += lazy[num];
    lazy[num] = 0;
}

void update(int num, int l, int r, int x, int y, ll dx)
{
    if (x <= l && y >= r) { tree[num] += (r - l + 1) * dx; lazy[num] += dx; return; }
    int m = l + r >> 1;
    pushdown(num, m - l + 1, r - m);
    if (x <= m) update(num * 2, l, m, x, y, dx);
    if (y >= m + 1) update(num * 2 + 1, m + 1, r, x, y, dx);
    tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

ll query(int num, int l, int r, int x, int y)
{
    if (x <= l && y >= r) return tree[num];
    int m = l + r >> 1;
    pushdown(num, m - l + 1, r - m);
	ll ans = 0;
    if (x <= m) ans += query(num * 2, l, m, x, y);
    if (y >= m + 1) ans += query(num * 2 + 1, m + 1, r, x, y);
    return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	getchar();
    build(1, 1, n);
    char tmp; int x, y; ll d;
    for (int i = 0; i < m; i++)
    {
    	scanf("%c", &tmp);
		if (tmp == 'Q') { scanf("%d %d", &x, &y); getchar(); printf("%lld\n", query(1, 1, n, x, y)); }
		else { scanf("%d %d %lld", &x, &y, &d); getchar(); update(1, 1, n, x, y, d); }
    }
    return 0;
}
