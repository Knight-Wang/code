#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pdi = pair<double, int>;
const int INF = 0x3f3f3f3f;
struct edge
{
	int to;
	double w;
};
vector<edge> G[205];
vector<pii> stop;
double d[205];
int square(int x)
{
	return x * x;
}
double cal_dis(int x, int y)
{
	return sqrt(square(stop[x].first - stop[y].first) + square(stop[x].second - stop[y].second));
}
double dij(int s, int t)
{
	for (int i = 0; i < (int)stop.size(); i++) d[i] = INF;
	d[s] = 0;
	priority_queue<pdi, vector<pdi>, greater<pdi>> q;
	q.push(pdi(0, s));
	while (!q.empty())
	{
		pdi tmp = q.top(); q.pop();
		int id = tmp.second;
		if (tmp.first > d[id]) continue;
		for (int i = 0; i < (int)G[id].size(); i++)
		{
			int son = G[id][i].to;
			if (d[id] + G[id][i].w < d[son])
			{
				d[son] = d[id] + G[id][i].w;
				q.push(pdi(d[son], son));
			}
		}
	}
	return d[t];
}
int main()
{
	int sx, sy, ex, ey, x, y;
	cin >> sx >> sy >> ex >> ey;
	stop.push_back(pii(sx, sy));
	int cnt = 1;
	while (cin >> x >> y)
	{
		if (x == -1 && y == -1) 
		{
			for (int i = cnt; i < (int)stop.size() - 1; i++)
			{
				double w = cal_dis(i, i + 1) / 40.0;
				G[i].push_back(edge{i + 1, w});
				G[i + 1].push_back(edge{i, w});
			}
			cnt = stop.size();
		}
		else stop.push_back(pii(x, y));
	}
	stop.push_back(pii(ex, ey));
	for (int i = 0; i < (int)stop.size(); i++)
	{
		for (int j = i + 1; j < (int)stop.size(); j++)
		{
			double w = cal_dis(i, j) / 10.0;
			G[i].push_back(edge{j, w});
			G[j].push_back(edge{i, w});
		}
	}
	double ans = dij(0, stop.size() - 1);
	ans = ans * 6.0 / 100.0;
	cout << int(ans + 0.5) << endl;
	return 0;
}