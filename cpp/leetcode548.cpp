class Solution
{
public:
    bool splitArray(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 7) return false;
        vector<int> sum(n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
        for (int j = 3; j <= n - 4; j++)
        {
            unordered_set<int> st;
            for (int i = 1; i < j - 1; i++)
            {
                if (sum[i - 1] == sum[j - 1] - sum[i]) st.insert(sum[i - 1]);
            }
            for (int k = j + 2; k <= n - 2; k++)
            {
                if (sum[k - 1] - sum[j] == sum[n - 1] - sum[k] && st.count(sum[k - 1] - sum[j]))
                    return true;
            }
        }
        return false;
    }
};