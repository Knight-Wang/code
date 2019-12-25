class Solution
{
public:
    int palindromePartition(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> m(n, vector<int>(n, 0x3f3f3f3f));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (j == i) m[i][j] = 0;
                else if (j == i + 1) m[i][j] = s[i] != s[j];
                else
                {
                    m[i][j] = m[i + 1][j - 1];
                    if (s[i] != s[j]) m[i][j]++;
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, 0x3f3f3f3f));
        for (int i = 0; i < n; i++)
        {
            dp[i][1] = m[0][i];
            for (int p = 2; p <= min(k, i + 1); p++)
            {
                for (int j = 0; j < i; j++)
                {
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + m[j + 1][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};