class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if (nums.empty()) return target == 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
        int n = tmp.size();
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; tmp[j] <= i && j < n; j++)
            {
                dp[i] += dp[i - tmp[j]];
            }
        }
        return dp[target];
    }
};