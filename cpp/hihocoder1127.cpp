#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1005;
vector<int> G[MAXN];
int n, m;
bool used[MAXN];
int match[MAXN];

bool dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];
		int w = match[u];
		if (w == -1 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int max_match()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (match[i] == -1)
		{
			memset(used, 0, sizeof(used));
			if (dfs(i))
				res++;
		}
	}
	return res;
}

int main()
{
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	memset(match, -1, sizeof(match));
	int ans = max_match();
	cout << ans << endl;
	cout << n - ans << endl;
	return 0;
}
