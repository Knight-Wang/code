#include <bits/stdc++.h>
using namespace std;
char a[105][105];
const int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
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
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			if (!ok) break;
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == '*') continue;
				else if (a[i][j] == '.')
				{
					bool flg = true;
					for (int k = 0; k < 8; k++)
					{
						int nx = i + dx[k], ny = j + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '*')
						{
							flg = false; break;
						}
					}
					if (!flg) { ok = false; break; }
				}
				else
				{
					int tmp = a[i][j] - '0', cnt = 0;
					bool flg = true;
					for (int k = 0; k < 8; k++)
					{
						int nx = i + dx[k], ny = j + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '*')
						{
							cnt++;
						}
					}
					if (cnt != tmp) { ok = false; break; }
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}