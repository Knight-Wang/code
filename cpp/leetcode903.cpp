class Solution
{
public:
    int numPermsDISequence(string S)
    {
        if (S.empty()) return 0;
        int n = S.length(), MOD = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++) dp[0][i] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (S[i - 1] == 'D')
            {
                dp[i & 1][n - i] = dp[i - 1 & 1][n - i + 1];
                for (int j = n - i - 1; j >= 0; j--)
                    dp[i & 1][j] = (dp[i & 1][j + 1] + dp[i - 1 & 1][j + 1]) % MOD;
            }
            else
            {
                dp[i & 1][0] = dp[i - 1 & 1][0];
                for (int j = 1; j <= n - i; j++)
                    dp[i & 1][j] = (dp[i - 1 & 1][j] + dp[i & 1][j - 1]) % MOD;
            }
        }
        return dp[n & 1][0];
    }
};