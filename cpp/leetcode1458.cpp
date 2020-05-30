class Solution
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -0x3f3f3f3f));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int tmp = dp[i + 1][j + 1] > 0 ? dp[i + 1][j + 1] : 0;
                dp[i][j] = nums1[i] * nums2[j] + tmp;
                dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};