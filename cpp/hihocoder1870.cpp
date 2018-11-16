#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
vector<int> G[25];
bool vis[25];
void dfs(int now)
{
	vis[now] = true;
	for (int i = 0; i < G[now].size(); i++)
	{
		if (!vis[G[now][i]]) dfs(G[now][i]);
	}
}
int main()
{
	int n, a, b;
	string x, y;
	while (cin >> n)
	{
		for (int i = 1; i <= 20; i++) G[i].clear();
		int cnt = 0;
		string ans = "";
		map<string, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			if (ans != "") continue;
			if (mp.count(x) && mp.count(y))
			{
				a = mp[x]; b = mp[y];
				memset(vis, 0, sizeof vis);
				dfs(b);
				if (vis[a]) { ans += x; ans += ' '; ans += y; }
				G[a].push_back(b);
			}
			else
			{
				if (mp.count(x)) a = mp[x];
				else a = mp[x] = ++cnt;
				if (mp.count(y)) b = mp[y];
				else b = mp[y] = ++cnt;
				G[a].push_back(b);
			}
		}
		if (ans == "") cout << 0 << endl;
		else cout << ans << endl;
	}
	return 0;
}