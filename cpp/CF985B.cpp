#include <bits/stdc++.h>
using namespace std;
char a[2005][2005];
int sum[2005];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		memset(sum, 0, sizeof sum);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				sum[j] += a[i][j] - '0';
			}
		}
		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				sum[j] -= a[i][j] - '0';
			}
			bool flg = true;
			for (int j = 0; j < m; j++)
			{
				if (sum[j] == 0) { flg = false; break; }
			}
			if (flg) { ans = i; break; }
			for (int j = 0; j < m; j++)
			{
				sum[j] += a[i][j] - '0';
			}
		}
		cout << (ans == -1 ? "NO":"YES") << endl;
	}
	return 0;
}