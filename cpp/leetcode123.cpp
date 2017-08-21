#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		vector<int> dp(5);
		int n = prices.size();
		dp[1] = dp[3] = -0x3f3f3f3f;
		dp[0] = dp[2] = dp[4] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[4] = max(dp[4], dp[3] + prices[i - 1]);
			dp[3] = max(dp[3], dp[2] - prices[i - 1]);
			dp[2] = max(dp[2], dp[1] + prices[i - 1]);
			dp[1] = max(dp[1], dp[0] - prices[i - 1]);
		}
		return dp[4];
	}
};
int main()
{
	Solution s;
	vector<int> prices = {1, 3, 2, 4};
	cout << s.maxProfit(prices) << endl;
	return 0;
}