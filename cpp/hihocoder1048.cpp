#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1000, MAXM = 5, MOD = 1e9 + 7;
int dp[MAXN + 1][MAXM + 1][1 << MAXM + 1], n, m;

pii next(int x, int y)
{
    pii res;
    res.first = y == m - 1 ? x + 1 : x;
    res.second = y == m - 1 ? 0 : y + 1;
    return res;
}

int main()
{
    cin >> n >> m;
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
						dp[i][j][k] %= MOD;
                    }
                }
            }
        }
    }
    cout << dp[0][0][0] << endl;
    return 0;
}