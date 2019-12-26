class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        for (int i = 0; i < 3; i++)
        {
            if (i == nums[0] % 3) dp[0][i] = nums[0];
            else if (i == 0) dp[0][i] = 0;
            else dp[0][i] = -0x3f3f3f3f;
        }
        for (int i = 1; i < n; i++)
        {
            int r = nums[i] % 3;
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - r + 3) % 3] + nums[i]);
            }
        }
        return max(0, dp[n - 1][0]);
    }
};