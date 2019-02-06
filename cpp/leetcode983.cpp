class Solution
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = min(dp[i], dp[i - 1] + costs[0]);
            int p = lower_bound(days.begin(), days.begin() + i, days[i - 1] - 6) - days.begin();
            for (int j = p; j < i; j++) dp[i] = min(dp[i], dp[j] + costs[1]);
            p = lower_bound(days.begin(), days.begin() + i, days[i - 1] - 29) - days.begin();
            for (int j = p; j < i; j++) dp[i] = min(dp[i], dp[j] + costs[2]);
        }
        return dp[n];
    }
};