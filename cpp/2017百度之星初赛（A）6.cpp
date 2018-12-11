#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 105, INF = 0x3f3f3f3f;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};

char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, minx, maxx, miny, maxy;

void dfs(int x, int y, char c)
{
	minx = min(minx, x); maxx = max(maxx, x);
	miny = min(miny, y); maxy = max(maxy, y);
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == c)
			dfs(nx, ny, c);
	}
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		memset(vis, 0, sizeof vis);
		int cnt0 = 0, cnt1 = 0;
		bool flg = true;
		for (int i = 0; i < n; i++)
		{
			if (!flg) break;
			for (int j = 0; j < m; j++)
			{
				if (!vis[i][j])
				{
					minx = INF, maxx = -INF;
					miny = INF, maxy = -INF;
					dfs(i, j, a[i][j]);
					if (a[i][j] == '0' && !(minx == 0 || maxx == n - 1 || miny == 0 || maxy == m - 1)) 
						cnt0++;
					else if (a[i][j] == '1' ) cnt1++;
				}
			}
		}
		if (cnt0 == 1 && cnt1 == 1) cout << 0 << endl;
		else if (cnt0 == 0 && cnt1 == 1) cout << 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}