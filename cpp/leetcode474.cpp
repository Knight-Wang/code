class Solution 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int l = strs.size(), dp[101][101];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < l; i++)
        {
            int zeros = 0, ones = 0;
            for (int j = 0; j < strs[i].length(); j++)
                if (strs[i][j] == '0') zeros++;
                else ones++;
            for (int j = m; j >= zeros; j--)
            {
                for (int k = n; k >= ones; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};