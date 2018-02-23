#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
vector<int> G[MAXN];
int in[MAXN], n, m;
string value;
int dp[MAXN][26];
bool solve()
{
	queue<int> q;
	for (int i = 1; i <= n; i++) 
	{
		if (!in[i]) 
		{
			q.push(i); dp[i][value[i - 1] - 'a'] = 1;
		}
	}
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int i = 0; i < G[x].size(); i++)
		{
			int to = G[x][i];
			for (int k = 0; k < 26; k++) 
			{	
				if (k == value[to - 1] - 'a') dp[to][k] = max(dp[to][k], dp[x][k] + 1);
				else dp[to][k] = max(dp[to][k], dp[x][k]);
			}
			in[to]--;
			if (!in[to]) q.push(to);
		}
	}
	for (int i = 1; i <= n; i++) if (in[i]) return false;
	return true;
}
int main()
{
	int x, y;
	cin >> n >> m >> value;
	set<pair<int, int>> s;
	bool flg = true;
	for (int i = 0; i < m; i++) 
	{ 
		cin >> x >> y;
		if (x == y) flg = false;
		pair<int, int> p(x, y);
		s.insert(p);
	}
	if (!flg) { cout << -1 << endl; return 0; }
	for (auto p: s) { G[p.first].push_back(p.second); in[p.second]++; }
	if (!solve()) cout << -1 << endl;
	else
	{
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 26; j++)
				maxn = max(maxn, dp[i][j]);
		}
		cout << maxn << endl;
	}
	return 0;
}