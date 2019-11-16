class Solution
{
public:
    int numRollsToTarget(int d, int f, int target)
    {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        int MOD = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++)
        {
            for (int k = 1; k <= target; k++)
            {
                for (int j = 1; j <= f; j++)
                {
                    if (k < j) continue;
                    dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % MOD;
                }
            }
        }
        return dp[d][target];
    }
};