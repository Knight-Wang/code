class Solution
{
public:
    int dfs(vector<int>& piles, int l, int r, int sum, vector<vector<int>>& dp)
    {
        if (l > r) return 0;
        if (l == r) return piles[l];
        if (dp[l][r] != -1) return dp[l][r];
        int x = dfs(piles, l + 1, r, sum - piles[l], dp);
        int y = dfs(piles, l, r - 1, sum - piles[r], dp);
        return dp[l][r] = max(sum - x, sum - y);
    }
    bool stoneGame(vector<int>& piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int res = dfs(piles, 0, n - 1, sum, dp);
        if (res * 2 > sum) return true;
        return false;
    }
};