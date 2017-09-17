class Solution 
{
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1), times(n, 0);
		times[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j] == dp[i] - 1) 
					times[i] += times[j];
            }
			if (!times[i]) times[i] = 1;
        }
        int tot = 0, maxn = 0;
		for (int i = 0; i < n; i++) maxn = max(maxn, dp[i]);
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxn) tot += times[i];
        }
        return tot;
    }
};