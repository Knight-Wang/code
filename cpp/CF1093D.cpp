#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAXN = 300005;

vector<int> G[MAXN];
int col[MAXN];
int n, m;
ll c1 = 0, c2 = 0, bin[MAXN];

bool dfs(int v, int c)
{
	col[v] = c;
	if (c == 1) c1++;
	else c2++;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (col[G[v][i]] == c) return false;
		if (col[G[v][i]] == 0 && !dfs(G[v][i], 3 - c)) return false;
	}
	return true;
}

int main()
{
	bin[0] = 1;
	for (int i = 1; i <= 300000; i++) bin[i] = bin[i - 1] * 2 % MOD;
	int t, v, u;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) { G[i].clear(); col[i] = 0; }
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bool flg = true;
		ll ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (col[i]) continue;
			ll tmp = 0; c1 = c2 = 0;
			if (!dfs(i, 1)) { flg = false; break; }
			tmp = (bin[c1] + bin[c2]) % MOD;
			ans = ans * tmp % MOD;
		}
		if (!flg) puts("0");
		else printf("%lld\n", ans);
	}
	return 0;
}