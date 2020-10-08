class Solution
{
public:
    int specialArray(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n, res = -1;
        while (l <= r)
        {
            int m = l + r >> 1;
            int p = nums.end() - lower_bound(nums.begin(), nums.end(), m);
            if (p > m) l = m + 1;
            else if (p < m) r = m - 1;
            else { res = p; break; }
        }
        return res;
    }
};
