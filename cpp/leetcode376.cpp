class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if (nums.size() <= 1) return nums.size();
        int n = nums.size(), maxn = 1;
        vector<int> dif(n - 1);
        for (int i = 0; i < n - 1; i++)
            dif[i] = nums[i + 1] - nums[i];
        vector<int> dp(n - 1);
        dp[0] = (dif[0] > 0);
        for (int i = 1; i < n - 1; i++)
        {
            if ((dp[i - 1] & 1) && (dif[i] < 0))
                dp[i] = dp[i - 1] + 1;
            else if (!(dp[i - 1] & 1) && (dif[i] > 0))
                dp[i] = dp[i - 1] + 1;
            else dp[i] = dp[i - 1];
        }
        maxn = max(maxn, dp[n - 2] + 1);
        dp[0] = (dif[0] < 0);
        for (int i = 1; i < n - 1; i++)
        {
            if ((dp[i - 1] & 1) && (dif[i] > 0))
                dp[i] = dp[i - 1] + 1;
            else if (!(dp[i - 1] & 1) && dif[i] < 0)
                dp[i] = dp[i - 1] + 1;
            else dp[i] = dp[i - 1];
        }
        maxn = max(maxn, dp[n - 2] + 1);
        return maxn;
    }
};