#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 205, INF = 0x3f3f3f3f;
int sx, sy, ex, ey;
double dis[MAXN][MAXN];

struct node
{
	int x, y;
};
node a[MAXN];

int square(int x)
{
	return x * x;
}

double cal(int i, int j)
{
	return sqrt((double)square(a[i].x - a[j].x) + (double)square(a[i].y - a[j].y));
}

int main()
{
	int x, y;
	cin >> sx >> sy >> ex >> ey;
	a[0].x = sx; a[0].y = sy;
	int tmp = 1, cnt = 1;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			dis[i][j] = INF;
		}
	}
	for (int i = 0; i < MAXN; i++) dis[i][i] = 0;
	while (cin >> x >> y)
	{
		if (x == -1 && y == -1) 
		{
			for (int i = tmp; i < cnt - 1; i++)
				dis[i][i + 1] = dis[i + 1][i] = cal(i, i + 1) / 40.0;
			tmp = cnt;
			continue;
		}
		a[cnt++].x = x; a[cnt - 1].y = y;
	}
	a[cnt].x = ex; a[cnt].y = ey;
	for (int i = 0; i <= cnt; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			dis[i][j] = dis[j][i] = min(dis[i][j], cal(i, j) / 10.0);
		}
	}
	for (int k = 0; k <= cnt; k++)
	{
		for (int i = 0; i <= cnt; i++)
		{
			for (int j = 0; j <= cnt; j++)
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
		}
	}
	
	cout << int(dis[0][cnt] / 1000.0 * 60.0 + 0.5) << endl;
	return 0;
}