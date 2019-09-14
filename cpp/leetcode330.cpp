class Solution
{
public:
    int minPatches(vector<int>& nums, int n)
    {
        int res = 0; long long maxn = 0;
        for (auto it: nums)
        {
            while (maxn < n && it > maxn + 1)
            {
                maxn += maxn + 1; res++;
            }
            maxn += it;
        }
        while (maxn < n)
        {
            maxn += maxn + 1;
            res++;
        }
        return res;
    }
};