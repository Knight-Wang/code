class Solution
{
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width)
    {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
        dp[0][0] = dp[0][1] = books[0][1];
        for (int i = 1; i < n; i++)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + books[i][1];
            int sum = books[i][0], maxn = books[i][1];
            for (int j = i - 1; j >= 0; j--)
            {
                if (sum + books[j][0] > shelf_width) break;
                maxn = max(maxn, books[j][1]);
                dp[i][0] = min(dp[i][0], dp[j][1] - books[j][1] + maxn);
                sum += books[j][0];
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};