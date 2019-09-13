class Solution
{
public:
	int dfs(int l, int r, int k, vector<int>& b, vector<vector<vector<int>>>& dp)
	{
		if (l > r) return 0;
		if (l == r) return (k + 1) * (k + 1);
		if (dp[l][r][k] != -1) return dp[l][r][k];
		int res = 0;
		for (int j = l + 1; j <= r; j++)
		{
			if (b[j] == b[l])
			{
				res = max(res, dfs(l + 1, j - 1, 0, b, dp) + dfs(j, r, k + 1, b, dp));
			}
			else
			{
				res = max(res, dfs(l, j - 1, k, b, dp) + dfs(j, r, 0, b, dp));
			}
		}
		return dp[l][r][k] = res;
	}
    int removeBoxes(vector<int>& boxes)
    {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(0, n - 1, 0, boxes, dp);
    }
};