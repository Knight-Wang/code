#include <bits/stdc++.h>
#define w 0
#define g 1
#define b 2
using namespace std;
const int N = 100;
vector<int> G[N + 1];
vector<int> vis, res;
bool cycle;
void init()
{
	cycle = false;
	for (int i = 0; i <= N; i++) vis.push_back(w);
	G[1].push_back(2);
	G[1].push_back(4);
	G[2].push_back(3);
	G[3].push_back(1);
}
void dfs(int u)
{
	if (vis[u] == b) return;
	if (vis[u] == g) { cycle = true; return; }
	vis[u] = g;
	for (int i = 0; i < (int)G[u].size(); i++)
	{
		dfs(G[u][i]);
	}
	vis[u] = b;
	res.push_back(u);
	return;
}
int main()
{
	init();
	dfs(1);
	cout << cycle << endl;
	for (int i = 0; i < (int)res.size(); i++) 
		cout << res[i] << " "; 
	cout << endl;
	return 0;
}