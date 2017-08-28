class Solution 
{
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    int findPaths(int m, int n, int N, int i, int j) 
    {
        int dp[2][m + 2][n + 2];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= N; i++)
        {   
            memset(dp[i & 1], 0, sizeof dp[i & 1]);
            for (int j = 0; j <= m; j++) 
                dp[(i - 1) & 1][j][0] = dp[(i - 1) & 1][j][n + 1] = 1;
            for (int j = 0; j <= n; j++)
                dp[(i - 1) & 1][0][j] = dp[(i - 1) & 1][m + 1][j] = 1;
            for (int j = 1; j <= m; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        int nx = j + dx[l], ny = k + dy[l];
                        dp[i & 1][j][k] = 
                        (dp[i & 1][j][k] + dp[(i - 1) & 1][nx][ny]) % 1000000007;
                    }
                }
            }
        }
        return dp[N & 1][i + 1][j + 1];
    }
};