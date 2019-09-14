class Solution
{
public:
    int numSquares(int n)
    {
        int m = n;
        while ((m & 3) == 0) m >>= 2;
        if (m % 8 == 7) return 4;
        int r = sqrt(n);
        if (r * r == n) return 1;
        else
        {
            for (int i = 1; i * i <= n; i++)
            {
                int l = sqrt(n - i * i);
                if (i * i + l * l == n) return 2;
            }
            return 3;
        }
    }
};