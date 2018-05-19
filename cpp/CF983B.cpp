#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int a[MAXN][MAXN];
int main()
{
	int n, q, l, r;
	while (cin >> n)
	{
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) cin >> a[i][i];
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= n - i + 1; j++)
			{
				a[j][j + i - 1] = a[j][j + i - 2] ^ a[j + 1][j + i - 1];
			}
		}
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= n - i + 1; j++)
			{
				a[j][j + i - 1] = max(a[j][j + i - 1], max(a[j][j + i - 2], a[j + 1][j + i - 1]));
			}
		}
		cin >> q;
		while (q--)
		{
			cin >> l >> r;
			cout << a[l][r] << endl;
		}
	}
	return 0;
}