class Solution
{
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width)
    {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0; dp[1] = books[0][1];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + books[i - 1][1];
            int sum = books[i - 1][0], maxn = books[i - 1][1];
            for (int j = i - 1; j >= 1; j--)
            {
                if (sum + books[j - 1][0] > shelf_width) break;
                maxn = max(maxn, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxn);
                sum += books[j - 1][0];
            }
        }
        return dp[n];
    }
};