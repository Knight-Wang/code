class Solution
{
public:
	int maxProfit(int k, vector<int>& prices)
	{
        int n = prices.size();
        int m = min(k, n / 2);
		vector<int> dp(2 * m + 1);
		for (int i = 0; i <= 2 * m; i++)
			dp[i] = (i & 1 ? -0x3f3f3f3f : 0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 2 * m; j >= 1; j--)
				dp[j] = max(dp[j], dp[j - 1] + (j & 1 ? -1 : 1) * prices[i - 1]);
		}
		return dp[2 * m];
	}
};