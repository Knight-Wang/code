class Solution 
{
public:
    int integerBreak(int n) 
    {
        int a[11] = {0, 1, 1, 2};
        if (n < 4) return a[n];
        int p = 1;
        while (n > 4)
        {
            p *= 3;
            n -= 3;
        }
        return p * n;
    }
};