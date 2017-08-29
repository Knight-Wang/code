class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        vector<int> dp(11, 0);
        dp[0] = 1; dp[1] = 10;
        int x = 9, now = 9;
        for (int i = 2; i < 11; i++)
        {
            dp[i] = dp[i - 1] + x * now;
            x *= now;
            now--;
        }
        if (n >= 11) return dp[10];
        return dp[n];
    }
};