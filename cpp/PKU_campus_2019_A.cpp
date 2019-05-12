#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
const ll mod = 10000019;
ll p[N], c[N], d[N], e[N];
void init()
{
	for (int i = 0; i < N; i++) p[i] = i;
}
int find(int x)
{
	if (p[x] == x) return x;
	return p[x] = find(p[x]); 
}
void uni(int x, int y)
{
	x = find(x); y = find(y);
	p[x] = y;
	d[y] += d[x];
	c[y] += c[x];
	e[y] += e[x];
}
int main()
{
	ios::sync_with_stdio(false);
	int T, n, m, a, b;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;		
		init();
		for (int i = 1; i < N; i++) d[i] = 1;
		memset(c, 0, sizeof c);
		memset(e, 0, sizeof e);
		ll ans = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> a >> b;
			int pa = find(a), pb = find(b);
			if (pa == pb)
			{
				c[pa]++;
				if (a == b) e[pa]++;
			}
			else uni(a, b);
		}
		for (int i = 1; i <= m; i++)
		{
			if (p[i] == i)
			{
				if (c[i] > 1) { ans = 0; break; }
				else if (c[i] == 1)
				{
					if (e[i] == 0) ans = ans * 2 % mod;
				}
				else ans = (ans * d[i]) % mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}