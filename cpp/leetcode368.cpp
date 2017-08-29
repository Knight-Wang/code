class Solution 
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        if (nums.empty()) return vector<int>();
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
        int n = tmp.size(), maxn = 0, pos = 0;
        vector<int> dp(n, 1), path(n, -1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (tmp[i] % tmp[j] == 0)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        path[i] = j;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > maxn)
            {
                maxn = dp[i]; pos = i;
            }
        }
        vector<int> ret;
        while (pos != -1)
        {
            ret.push_back(tmp[pos]);
            pos = path[pos];
        }
        return ret;
    }
};