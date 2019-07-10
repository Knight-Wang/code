class Solution
{
public:
    string longestPalindrome(string s) 
    {
        if (s == "") return s;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ans = ""; int maxn = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j) dp[i][j] = true;
                else if (j == i + 1) dp[i][j] = (s[i] == s[j]);
                else if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
                if (dp[i][j] && j - i + 1 > maxn)
                {
                    maxn = j - i + 1; ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};