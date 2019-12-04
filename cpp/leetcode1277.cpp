class Solution
{
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) dp[i][0] = (matrix[i][0] == 1);
        for (int i = 0; i < m; i++) dp[0][i] = (matrix[0][i] == 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0) dp[i][j] = 0;
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) res += accumulate(dp[i].begin(), dp[i].end(), 0);
        return res;
    }
};