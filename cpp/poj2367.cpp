#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define w 0
#define g 1
#define b 2
using namespace std;
const int N = 105;
int G[N][N];
vector<int> res, vis;
bool cycle;
int n, m;
void init()
{
	cycle = false;
	cin >> n;
	memset(G, 0, sizeof G);
	for (int i = 0; i <= n; i++) vis.push_back(w);
	int x;
	for (int i = 1; i <= n; i++)
	{
		while (cin >> x, x)
		{
			G[i][x] = 1;
		}
	}
}
void dfs(int u)
{
	if (vis[u] == b) return;
	if (vis[u] == g) { cycle = true; return; }
	vis[u] = g;
	for (int i = n; i >= 1; i--)
	{
		if (G[u][i]) dfs(i);
	}
	vis[u] = b;
	res.push_back(u);
	return;
}
void topsort()
{
	for (int i = n; i >= 1; i--)
	{
		if (vis[i] == w) dfs(i);
	}
	reverse(res.begin(), res.end());
}
int main()
{
	init();
	topsort();
	if (cycle) cout << "There is a cycle in G!" << endl;
	else
	{
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}