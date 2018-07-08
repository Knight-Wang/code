class Solution 
{
public:
    bool check(int r, int x)
    {
        return r <= x / r;
    }
    int mySqrt(int x) 
    {
        if (x <= 0) return 0;
        int l = 1, r = x, ans = -1;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(m, x))
            {
                ans = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        return ans;
    }
};