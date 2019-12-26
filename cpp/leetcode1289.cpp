class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0x3f3f3f3f));
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = arr[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> l(m, 0x3f3f3f3f), r(m, 0x3f3f3f3f);
            for (int j = 1; j < m; j++)
            {
                l[j] = min(l[j - 1], dp[i - 1][j - 1]);
            }
            for (int j = m - 2; j >= 0; j--)
            {
                r[j] = min(r[j + 1], dp[i - 1][j + 1]);
            }
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = min(l[j], r[j]) + arr[i][j];
            }
        }
        int minn = INT_MAX;
        for (int i = 0; i < m; i++) minn = min(minn, dp[n - 1][i]);
        return minn;
    }
};