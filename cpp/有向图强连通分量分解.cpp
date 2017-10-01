#include <bits/stdc++.h>
using namespace std;
const int V = 12;
vector<int> G[100], rG[100], vs;
bool vis[100];
int cmp[100];
void add_edge(int from, int to)
{
	G[from].push_back(to); rG[to].push_back(from);
}
void dfs(int u)
{
	vis[u] = true;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (!vis[G[u][i]]) dfs(G[u][i]);
	}
	vs.push_back(u);
}
void rdfs(int u, int k)
{
	vis[u] = true;
	cmp[u] = k;
	for (int i = 0; i < rG[u].size(); i++)
	{
		if (!vis[rG[u][i]]) rdfs(rG[u][i], k);
	}
}
int scc()
{
	memset(vis, 0, sizeof vis);
	vs.clear();
	for (int i = 1; i <= V; i++)
	{
		if (!vis[i]) dfs(i);
	}
	memset(vis, 0, sizeof vis);
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--)
	{
		if (!vis[vs[i]]) rdfs(vs[i], k++); 
	}
	return k;
}
void init()
{
	add_edge(12, 11);
	add_edge(11, 10);
	add_edge(11, 8);
	add_edge(8, 10);
	add_edge(9, 8);
	add_edge(10, 9);
	add_edge(9, 7);
	add_edge(7, 6);
	add_edge(5, 7);
	add_edge(6, 5);
	add_edge(6, 4);
	add_edge(6, 3);
	add_edge(4, 3);
	add_edge(3, 2);
	add_edge(2, 3);
	add_edge(4, 1);
}
int main()
{
	init();
	cout << scc() << endl;
	for (int i = 1; i <= V; i++)
	{
		cout << cmp[i] << " ";
	}
	cout << endl;
	return 0;
}