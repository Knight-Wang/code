#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 105, MAXM = 105;

int n, m, s;
double d, dist[MAXN];
struct edge
{
	int from, to;
	double c, r;
};
edge es[2 * MAXM];

bool check(int s, double d)
{
	for (int i = 1; i <= n; i++) dist[i] = 0;
	dist[s] = d;
	bool update = true;
	while (update)
	{
		if (dist[s] > d) return true;
		update = false;
		for (int i = 1; i <= 2 * m; i++)
		{
			edge & e = es[i];
			if (dist[e.from] > 0 && dist[e.to] < (dist[e.from] - e.c) * e.r)
			{
				dist[e.to] = (dist[e.from] - e.c) * e.r;
				update = true;
			}
		}
	}
	return dist[s] > d;
}

int main()
{
	//freopen("D:\\codes\\tmp\\in.txt", "r", stdin);
	cin >> n >> m >> s >> d;
	for (int i = 1; i < 2 * m; i += 2)
	{
		cin >> es[i].from >> es[i].to >> es[i].r >> es[i].c;
		cin >> es[i + 1].r >> es[i + 1].c;
		es[i + 1].from = es[i].to;
		es[i + 1].to = es[i].from;
	}
	if (!check(s, d)) puts("NO");
	else puts("YES");
}