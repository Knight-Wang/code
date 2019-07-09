class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int ans = 0, n = prices.size(), minn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (prices[i] > minn) ans = max(ans, prices[i] - minn);
            minn = min(minn, prices[i]);
        }
        return ans;
    }
};