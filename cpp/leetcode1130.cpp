class Solution
{
public:
    int mctFromLeafValues(vector<int>& arr)
    {
        int n = arr.size();
        vector<vector<int>> maxn(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (j == i) maxn[i][j] = arr[i];
                else
                {
                    maxn[i][j] = max(maxn[i][j - 1], arr[j]);
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (j == i) dp[i][j] = arr[i];
                else if (j == i + 1) dp[i][j] = arr[i] * arr[j];
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + arr[i] * maxn[i + 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + arr[j] * maxn[i][j - 1]);
                    for (int k = i + 1; k < j - 1; k++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxn[i][k] * maxn[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};