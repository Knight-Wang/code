#include <iostream>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
char a[1005][1005], b[1005][1005];
int ok[1005][1005];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
					ok[i][j] = 0;
				else ok[i][j] = 1;
			}
		}
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (a[i][j] == '.')
				{
					for (int k = 0; k < 8; k++)
					{
						int nx = i + dx[k], ny = j + dy[k];
						ok[nx][ny] = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (ok[i][j])
				{
					for (int k = 0; k < 8; k++)
					{
						int nx = i + dx[k], ny = j + dy[k];
						b[nx][ny] = '#';
					}
				}
			}
		}
		bool flg = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == '#' && b[i][j] != '#')
				{
					flg = false; break;
				}
			}
		}
		cout << (flg ? "yes" : "no") << endl;
	}
	return 0;
}
