class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int> dp(4);
        dp[0] = dp[2] = 0;
        dp[1] = dp[3] = -0x3f3f3f3f;
        int n = prices.size();
        for (int i = 1; i <= n; i++)
        {
            dp[3] = dp[2];
            dp[2] = max(dp[2], dp[1] + prices[i - 1]);
            dp[1] = max(dp[1], dp[0] - prices[i - 1]);
            dp[0] = max(dp[0], dp[3]);
        }
        return max(dp[2], dp[3]);
    }
};