#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
const int MAXX = 200005;
struct node
{
	int v, x;
};
node a[MAXN];
int n;
ll bit0[MAXX], bit1[MAXX];
inline int lowbit(int x) { return x & -x; }
void add(ll * bit, int i, int dx)
{
	while (i <= MAXX) { bit[i] += dx; i += lowbit(i); }
}
ll sum(ll * bit, int i)
{
	ll ans = 0;
	while (i) { ans += bit[i]; i -= lowbit(i); }
	return ans;
}
bool cmp(const node & a, const node & b)
{
	return a.v < b.v;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &a[i].v, &a[i].x);
	sort(a, a + n, cmp);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll c = sum(bit0, a[i].x), s = sum(bit1, a[i].x);
		ans += (a[i].x * c - s) * a[i].v;
		c = sum(bit0, MAXX) - c; s = sum(bit1, MAXX) - s;
		ans += (s - c * a[i].x) * a[i].v;
		add(bit0, a[i].x, 1); add(bit1, a[i].x, a[i].x);
	}
	printf("%lld\n", ans);
	return 0;
}