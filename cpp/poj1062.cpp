#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 105, INF = 0x3f3f3f3f;

int M, N, P[MAXN], L[MAXN], X, dist[MAXN];
struct edge
{
	int to, cost;
};
vector<edge> G[MAXN];

int Dijkstra(int s, int l, int r)
{
	fill(dist + 1, dist + N + 1, INF);
	dist[s] = 0;
	priority_queue<pair<int, int> > q;
	q.push(pair<int, int>(0, s));
	while (!q.empty())
	{
		pair<int, int> tmp = q.top(); q.pop();
		int id = tmp.second;
		if (tmp.first > dist[id]) continue;
		for (unsigned int i = 0; i < G[id].size(); i++)
		{
			edge & e = G[id][i];
			if (dist[e.to] >= dist[id] + e.cost && L[e.to] >= l && L[e.to] <= r)
			{
				dist[e.to] = dist[id] + e.cost;
				q.push(pair<int, int>(dist[e.to], e.to));
			}
		}
	}
	int minn = INF;
	for (int i = 1; i <= N; i++)
		minn = min(minn, dist[i] + P[i]);
	return minn;
}

int main()
{
	//freopen("d:\\codes\\tmp\\in.txt", "r", stdin);
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i] >> L[i] >> X;
		int id, cost;
		for (int j = 0; j < X; j++)
		{
			cin >> id >> cost;
			G[i].push_back(edge{id, cost});
		}
	}
	int l = L[1], ans = INF;
	for (int i = max(l - M, 0); i <= l; i++)
	{
		int p = i, q = i + M;
		ans = min(ans, Dijkstra(1, p, q));
	}
	cout << ans << endl;
	return 0;
}
