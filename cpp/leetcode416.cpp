class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int n = nums.size(), dp[sum / 2 + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = sum / 2; j >= nums[i]; j--)
            {
                dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[sum / 2];
    }
};