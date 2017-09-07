class Solution 
{
public:
    bool dfs(int cur, int len, int sum, int des, vector<int>& dp)
    {
        if (sum >= des) return false;
        if (dp[cur] != -1) return dp[cur];
        for (int i = 0; i < len; i++)
        {
            int tmp = 1 << i;
            if (!(cur & tmp))
            {
                if (!dfs(cur | tmp, len, sum + i + 1, des, dp)) 
                    return dp[cur] = true;
            }
        }
        return dp[cur] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        if (!desiredTotal) return true;
        if ((maxChoosableInteger * (maxChoosableInteger + 1) / 2) < desiredTotal)
            return false;
        vector<int> dp(1100000, -1);
        return dfs(0, maxChoosableInteger, 0, desiredTotal, dp);
    }
};