#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 11, MAXM = 11;
typedef pair<int, int> pii;
typedef long long ll;
ll dp[MAXN + 1][MAXM + 1][1 << MAXM + 1];
int n, m;

pii next(int x, int y)
{
	pii res;
	res.first = y == m - 1 ? x + 1 : x;
	res.second = y == m - 1 ? 0 : y + 1;
	return res;
}

int main()
{
	while (cin >> n >> m, n || m)
	{
		memset(dp, 0, sizeof dp);
		dp[n][0][0] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				for (int k = 0; k < 1 << m; k++)
				{
					pii tmp = next(i, j);
					if (k >> j & 1)
						dp[i][j][k] = dp[tmp.first][tmp.second][k & ~(1 << j)];
					else
					{
						dp[i][j][k] = dp[tmp.first][tmp.second][k | 1 << j];
						if (j < m - 1 && !(k >> j + 1 & 1))
						{
							tmp = next(i, j + 1);
							dp[i][j][k] += dp[tmp.first][tmp.second][k];
						}
					}
				}
			}
		}
		cout << dp[0][0][0] << endl;
	}
	return 0;
}