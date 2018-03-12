#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	static const int MAXN = 101;
	static const int INF = 0x3f3f3f3f;
    vector<pair<int, int>> G[MAXN];
	vector<bool> vis;
    vector<vector<int>> dp;
    Solution()
    {
        for (int i = 0; i < MAXN; i++) vis.push_back(false);
        for (int i = 0; i < MAXN; i++) dp.push_back(vector<int>(MAXN, -1));
    }
	int dfs(int now, int dst, int k, int K)
	{
		if (now == dst) return 0;
        if (dp[now][k] != -1) return dp[now][k];
		if (k > K) return INF;
		int minn = INF;
		vis[now] = true;
		for (int i = 0; i < G[now].size(); i++)
		{
			if (!vis[G[now][i].first])
			{
				vis[G[now][i].first] = true;
				minn = min(minn, dfs(G[now][i].first, dst, k + 1, K) + G[now][i].second);
				vis[G[now][i].first] = false;
			}
		}
		return dp[now][k] = minn;
	}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
	{
		for (int i = 0; i < flights.size(); i++)
		{
			int s = flights[i][0], t = flights[i][1], cost = flights[i][2];
			G[s].push_back(make_pair(t, cost));
		}
        int ans = dfs(src, dst, 0, K);
        return ans == INF ? -1 : ans;
    }
};
