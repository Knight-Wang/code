class Solution
{
public:
    int splitArray(vector<int>& nums, int m)
	{
		int n = nums.size();
		vector<int> sum(n + 1, 0);
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
		for (int i = 1; i <= n; i++) dp[i][1] = sum[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 2; j <= min(m, i); j++)
			{
				for (int k = 1; k < i; k++)
				{
					int tmp = sum[i] - sum[k];
					dp[i][j] = min(dp[i][j], max(tmp, dp[k][j - 1]));
				}
			}
		}
		return dp[n][m];
    }
};