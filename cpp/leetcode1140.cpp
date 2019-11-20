class Solution
{
public:
    int dfs(vector<int>& sum, int cur, int M, vector<vector<int>>& dp)
    {
        int n = sum.size(); 
        if (n - cur <= 2 * M) return sum[n - 1] - sum[cur];
        if (dp[cur][M] != -1) return dp[cur][M];
        int ans = INT_MIN;
        for (int i = 1; i <= min(2 * M, n - cur); i++)
        {
            int tmp = dfs(sum, cur + i, max(M, i), dp);
            ans = max(ans, sum[cur + i - 1] - sum[cur] + sum[n - 1] - sum[cur + i - 1] - tmp);
        }
        return dp[cur][M] = ans;
    }
    int stoneGameII(vector<int>& piles)
    {
        int n = piles.size();
        vector<int> sum(n + 1, 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + piles[i - 1];
        int res = dfs(sum, 0, 1, dp);
        return res;
    }
};