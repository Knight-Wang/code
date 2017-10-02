#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int a[20][20], b[20][20], ans[20][20], buf[20][20], m, n;
void turn(int x, int y)
{
	b[x][y] = 1 - b[x][y];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n)
		{
			b[nx][ny] = 1 - b[nx][ny];
		}
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	int minn = INF;
	for (int i = 0; i < (1 << n); i++)
	{
		int cnt = 0;
		memset(buf, 0, sizeof buf);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[i][j] = a[i][j];
			}
		}
		for (int j = 0; j < n; j++)
		{
			int msk = 1 << j;
			if (i & msk)
			{
				turn(0, j); cnt++; buf[0][j] = 1;
			}
		}
		for (int j = 1; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (b[j - 1][k]) 
				{	
					turn(j, k); cnt++; buf[j][k] = 1;
				}
			}
		}
		bool flg = true;
		for (int i = 0; i < n; i++)
		{
			if (b[m - 1][i]) { flg = false; break; }
		}
		if (flg && cnt < minn) 
		{
			minn = cnt;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					ans[i][j] = buf[i][j];
				}
			}
		}
	}
	if (minn == INF) cout << "IMPOSSIBLE" << endl;
	else
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}