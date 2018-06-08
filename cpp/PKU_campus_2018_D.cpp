#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 405, INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
string s[MAXN];
int d[MAXN][MAXN];
int par[MAXN]; 
ll num[MAXN];
struct edge
{
	int a, b, l;
};
edge es[MAXN * MAXN];
void init(int n)
{
	for (int i = 0; i < n; i++) { par[i] = i; num[i] = 1; }
}
int find(int x)
{
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
int uni(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return x;
	par[x] = y; return y;
}
int edit_dis(string a, string b)
{
	int la = a.length(), lb = b.length();
	for (int i = 0; i <= la; i++) d[i][0] = i;
	for (int i = 0; i <= lb; i++) d[0][i] = i;
	for (int i = 1; i <= la; i++)
	{
		for (int j = 1; j <= lb; j++)
		{
			if (a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1];
			else d[i][j] = min(d[i][j - 1], d[i - 1][j]) + 1;
		}
	}
	return d[la][lb];
}
bool cmp(edge & x, edge & y)
{
	return x.l < y.l;
}
bool check(int x, int cnt)
{
	int minn = INF, maxn = -INF;
	for (int i = 0; i < cnt; i++)
	{
		int px = find(es[i].a), py = find(es[i].b);
		if (px == x && py == x) maxn = max(maxn, es[i].l);
		else if ((px == x && py != x) || (px != x && py == x))
			minn = min(minn, es[i].l);
	}
	return maxn < minn;
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		init(n);
		for (int i = 0; i < n; i++) cin >> s[i];
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				es[cnt].a = i; es[cnt].b = j; es[cnt].l = edit_dis(s[i], s[j]);
				cnt++;
			}
		}
		sort(es, es + cnt, cmp);
		ll ans = 0; int tot = n;
		for (int i = 0; i < cnt; i++)
		{
			int px = find(es[i].a), py = find(es[i].b);
			if (px == py) continue;
			int tmp = uni(es[i].a, es[i].b);
			num[tmp] = num[px] * num[py] % MOD;
			if (check(tmp, cnt)) num[tmp] = (num[tmp] + 1) % MOD;
			tot--;
			if (tot == 1) ans = num[tmp];
		}
		cout << ans << endl;
	}
	return 0;
}