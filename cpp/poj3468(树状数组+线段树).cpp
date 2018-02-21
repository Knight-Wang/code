#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll bit[MAXN], tree[MAXN * 4];
int n, m;

int lowbit(int x) { return x & -x; }

void add(int i, ll x)
{
	while (i <= n) { bit[i] += x; i += lowbit(i); }
}

ll sum(int i)
{
	ll ans = 0;
	while (i) { ans += bit[i]; i -= lowbit(i); }
	return ans;
}

void update(int num, int l, int r, int x, ll dx)
{
	if (l == r) { tree[num] += dx; return; }
	int m = l + r >> 1;
	if (x <= m) update(num * 2, l, m, x, dx);
	else update(num * 2 + 1, m + 1, r, x, dx);
	tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

ll query(int num, int l, int r, int x, int y)
{
	if (x <= l && y >= r) return tree[num];
	int m = l + r >> 1;
	ll ans = 0;
	if (x <= m) ans += query(num * 2, l, m, x, y);
	if (y >= m + 1) ans += query(num * 2 + 1, m + 1, r, x, y);
	return ans;
}

ll get_ans(int x)
{
	if (x < 1) return 0;
	return x * sum(x) - query(1, 1, n + 1, 1, x);
}

int main()
{
	scanf("%d %d", &n, &m);
	char tmp; int x, y; ll d;
	for (int i = 1; i <= n; i++) 
	{ 
		scanf("%lld", &d);
		add(i, d); add(i + 1, -d);
		update(1, 1, n + 1, i, (i - 1) * d); 
		update(1, 1, n + 1, i + 1, -i * d); 
	}
	getchar();
    for (int i = 0; i < m; i++)
    {
    	scanf("%c", &tmp);
		if (tmp == 'Q') 
		{ 
			scanf("%d %d", &x, &y); getchar();
			ll r = get_ans(y); 
			ll l = get_ans(x - 1);
			printf("%lld\n", r - l);
		}
		else 
		{ 
			scanf("%d %d %lld", &x, &y, &d); getchar();
			add(x, d);
			add(y + 1, -d);
			update(1, 1, n + 1, x, ((ll)x - 1) * d);
			update(1, 1, n + 1, y + 1, -(ll)y * d);
		}
    }
	return 0;
} 
