class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int hold = -prices[0], sold = 0, n = prices.size() - 1;
        for (int i = 1; i <= n; i++)
        {
            sold = max(sold, hold + prices[i] - fee);
            hold = max(hold, sold - prices[i]);
        }
        return sold;
    }
};