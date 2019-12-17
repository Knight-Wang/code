#include <bits/stdc++.h>
using namespace std;
const int N = 81;
const int INF = 0x3f3f3f3f;
int a[N][N], b[N][N];
bitset<N * N * 4> dp[N][N];

int main()
{
    int h, w;
    while (cin >> h >> w)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> b[i][j];
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                dp[i][j].reset();
            }
        }
        dp[0][0][a[0][0] - b[0][0] + N * N * 2] = 1;
        dp[0][0][b[0][0] - a[0][0] + N * N * 2] = 1;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int tmp = abs(a[i][j] - b[i][j]);
                if (j)
                {
                    dp[i][j] |= dp[i][j - 1] << tmp;
                    dp[i][j] |= dp[i][j - 1] >> tmp;
                }
                if (i)
                {
                    dp[i][j] |= dp[i - 1][j] << tmp;
                    dp[i][j] |= dp[i - 1][j] >> tmp;
                }
            }
        }
        int res = INF;
        for (int i = 0; i < N * N * 4; i++)
        {
            if (dp[h - 1][w - 1][i]) res = min(res, abs(i - N * N * 2));
        }
        cout << res << endl;
    }
    return 0;
}