#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 0x3f3f3f3f;

char a[2005][2005];
int n, m, r, c, L, R;
int d[2005][2005];

int main()
{
	while (cin >> n >> m >> r >> c >> L >> R)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				d[i][j] = INF;
			}
		}
		r--; c--;
		queue<pii> q;
		q.push(pii(r, c));
		d[r][c] = 0;
		while (!q.empty())
		{
			pii tmp = q.front();
			q.pop();
			int x = tmp.first, y = tmp.second;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '.')
				{
					int nd = d[x][y] + (i == 3);
					if (nd < d[nx][ny])
					{
						q.push(pii(nx, ny));
						d[nx][ny] = d[x][y] + (i == 3);
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (d[i][j] <= L && d[i][j] + j - c <= R) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
