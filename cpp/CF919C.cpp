#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
char a[MAXN][MAXN];
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				cnt += a[i][j] == '.';
			}
		for (int i = 0; i < n; i++) a[n][i] = a[i][m] = '*';
		if (k > n && k > m) { cout << 0 << endl; continue; }
		if (k == 1) { cout << cnt << endl; continue; }
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int j = 0;
			while (j < m && a[i][j] != '.') j++;
			int s = j;
			while (j < m)
			{
				while (j < m && a[i][j] != '*') j++;
				sum += j - s >= k ? (j - s - k + 1) : 0;
				while (j < m && a[i][j] != '.') j++;
				s = j;
			}
		}
		for (int i = 0; i < m; i++)
		{
			int j = 0;
			while (j < n && a[j][i] != '.') j++;
			int s = j;
			while (j < n)
			{
				while (j < n && a[j][i] != '*') j++;
				sum += j - s >= k ? (j - s - k + 1) : 0;
				while (j < n && a[j][i] != '.') j++;
				s = j;
			}
		}
		cout << sum << endl;
	}
	return 0;
}