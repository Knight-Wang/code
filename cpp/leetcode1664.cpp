class Solution
{
public:
    int waysToMakeFair(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (i & 1) s[i] = s[i - 1] + nums[i - 1];
            else s[i] = s[i - 1] - nums[i - 1];
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == s[n] - s[i]) res++;
        }
        return res;
    }
};