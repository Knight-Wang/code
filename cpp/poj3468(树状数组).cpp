#include <cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll bit0[MAXN], bit1[MAXN];
int n, m;

int lowbit(int x) { return x & -x; }

void add(ll * bit, int i, ll x)
{
	while (i <= n) { bit[i] += x; i += lowbit(i); }
}

ll sum(ll * bit, int i)
{
	ll ans = 0;
	while (i) { ans += bit[i]; i -= lowbit(i); }
	return ans;
}

ll query(int x)
{
	return x * sum(bit0, x) - sum(bit1, x);
}

int main()
{
	scanf("%d %d", &n, &m);
	char tmp; int x, y; ll d;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lld", &d);
		add(bit0, i, d);
		add(bit0, i + 1, -d);
		add(bit1, i, (i - 1) * d);
		add(bit1, i + 1, -i * d);
	}
	getchar();
    for (int i = 0; i < m; i++)
    {
    	scanf("%c", &tmp);
		if (tmp == 'Q') 
		{ 
			scanf("%d %d", &x, &y); getchar();
			ll r = query(y), l = query(x - 1);
			printf("%lld\n", r - l);
		}
		else 
		{ 
			scanf("%d %d %lld", &x, &y, &d); getchar();
			add(bit0, x, d);
			add(bit0, y + 1, -d);
			add(bit1, x, (x - 1) * d);
			add(bit1, y + 1, -y * d);
		}
    }
	return 0;
} 
