class Solution 
{
public:
    bool judge(vector<string>& wordDict, string s)
    {
        return find(wordDict.begin(), wordDict.end(), s) != wordDict.end();
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> dp(s.length() + 1, 0);
        dp[0] = true;
        for (int i = 1; i <= (int)s.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && judge(wordDict, s.substr(j, i - j)))
                {
                    dp[i] = true;
                }
            }
        }
        return dp[s.length()];
    }
};