#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

bool in[100005];
int d[100005], s[100005];

struct edge
{
	int to, cost;	
};
vector<edge> G[100005];

int main()
{
	int n, m, k, a, b, l;
	while (cin >> n >> m >> k)
	{
		for (int i = 1; i <= n; i++) G[i].clear();
		set<int> st;
		for (int i = 1; i <= k; i++) { cin >> s[i]; st.insert(s[i]); }
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> l;
			edge e;
			e.to = b;
			e.cost = l;
			G[a].push_back(e);
			e.to = a;
			G[b].push_back(e);
		}
		queue<int> myQueue;
		for (int i = 1; i <= n; i++)
		{
			d[i] = INF;
			in[i] = false;
		}
		d[s[1]] = 0;
		myQueue.push(s[1]);
		while(!myQueue.empty())
		{
			int temp = myQueue.front(); myQueue.pop();
			if (in[temp]) in[temp] = false;
			for (int i = 0; i < G[temp].size(); i++)
			{
				edge e = G[temp][i];
				int to = e.to;
				int cost = e.cost;
				if (d[to] > max(d[temp], cost))
				{
					d[to] = max(d[temp], cost);
					if (!in[to])
					{
						myQueue.push(to);
						in[to] = true;
					}
				}
			}
		}
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			if (st.count(i)) maxn = max(maxn, d[i]);
		}
		for (int i = 1; i <= k; i++) cout << maxn << " ";
		cout << endl;
	}
	return 0;
}