#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int a[MAXN], par[MAXN], buf[MAXN];
typedef long long ll;
void init(int n)
{
	for (int i = 0; i < n; i++) par[i] = i;
}
int find(int x)
{
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void uni(int x, int y)
{
	x = find(x); y = find(y);
	if (x != y) par[x] = y;
}
bool check(int x, int y)
{
	if ((ll)a[x] * a[y] < 0) return false;
	ll tmp = (ll)a[x] * a[y];
	ll root = sqrt(tmp);
	return root * root == tmp;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		init(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (!a[i] || !a[j])
				{
					if (!a[i] && !a[j]) uni(i, j);
					else continue;
				}
				if (check(i, j)) uni(i, j);
			}
		}
		vector<int> fa(n, 0), ans(n + 1, 0); 
		int zero = -1;
		for (int i = 0; i < n; i++) 
		{ 
			fa[i] = find(i);
			if (a[i] == 0) zero = i;
		}
		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			memset(buf, 0, sizeof buf);
			for (int j = i; j < n; j++)
			{
				if (!buf[fa[j]]) { buf[fa[j]]++; cnt++; }
				if (cnt > 1 && zero != -1 && buf[fa[zero]]) ans[cnt - 1]++;
				else ans[cnt]++;
			}
		}
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}