#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.length();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j == i + 1) dp[i][j] = (s[i] == s[j] ? 1 : 2);
                else dp[i][j] = j - i + 1;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    if (s[k] == s[j])
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    cout << Solution().strangePrinter("aba") << endl;
    cout << Solution().strangePrinter("aaabbb") << endl;
    cout << Solution().strangePrinter("krkdttnyoqwygja") << endl;
    cout << Solution().strangePrinter("hello") << endl;
    return 0;
}