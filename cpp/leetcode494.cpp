class Solution 
{
public:
    
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S > sum || S < -sum || ((S + sum) & 1)) return 0;
        int n = nums.size();
		sum = (S + sum) >> 1;
		int dp[sum + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
			for (int j = sum; j >= nums[i - 1]; j--)
			{
				dp[j] += dp[j - nums[i - 1]];
			}
        }
        return dp[sum];
    }
};