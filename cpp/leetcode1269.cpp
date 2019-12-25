class Solution
{
public:
    int MOD = 1e9 + 7;
    int dfs(int p, int s, vector<vector<int>>& dp, int arrLen)
    {
        if (s == 0) return p == 0;
        else if (p > s) return 0;
        else if (dp[p][s] != -1) return dp[p][s];
        int res = dfs(p, s - 1, dp, arrLen);
        if (p > 0) res = (res + dfs(p - 1, s - 1, dp, arrLen)) % MOD;
        if (p < arrLen - 1) res = (res + dfs(p + 1, s - 1, dp, arrLen)) % MOD;
        return dp[p][s] = res;
    }
    int numWays(int steps, int arrLen)
    {
        vector<vector<int>> dp(steps / 2 + 1, vector<int>(steps + 1, -1));
        return dfs(0, steps, dp, arrLen);
    }
};