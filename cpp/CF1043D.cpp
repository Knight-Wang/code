#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int a[11][100001], reach[11][100001], n, m;

int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(reach, 0, sizeof reach);
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		}
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) v[a[1][i]] = i;
		for (int i = 2; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				a[i][j] = v[a[i][j]];
		}
		for (int i = 1; i <= n; i++) reach[1][i] = n;
		for (int i = 2; i <= m; i++)
		{
			int j = 1, start = 1;
			while (j <= n)
			{
				while (j + 1 <= n && a[i][j + 1] == a[i][j] + 1) j++;
				while (start <= j) { reach[i][a[i][start]] = a[i][j]; start++; }
				start = ++j;
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int minn = INF;
			for (int j = 1; j <= m; j++)
				if (reach[j][i])
					minn = min(minn, reach[j][i] - i + 1);
			if (minn != INF) ans += minn;
		}
		printf("%lld\n", ans);
	}
	return 0;
}