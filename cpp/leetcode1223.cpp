class Solution
{
public:
    int dieSimulator(int n, vector<int>& rollMax) 
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16, 0)));
        vector<vector<int>> sum(n, vector<int>(6, 0));
        int MOD = 1e9 + 7;
        for (int i = 0; i < 6; i++)
        {
            sum[0][i] = dp[0][i][1] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int p = 0; p < 6; p++)
                {
                    if (p == j) continue;
                    dp[i][j][1] = (dp[i][j][1] + sum[i - 1][p]) % MOD;
                }
                sum[i][j] = (sum[i][j] + dp[i][j][1]) % MOD;
                for (int k = 2; k <= rollMax[j]; k++)
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                    sum[i][j] = (sum[i][j] + dp[i][j][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 6; i++)
        {
            ans = (ans + sum[n - 1][i]) % MOD;
        }
        return ans;
    }
};