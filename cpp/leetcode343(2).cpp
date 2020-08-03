class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3) return n - 1;
        int r = n % 3;
        if (r == 0) return pow(3, n / 3);
        else if (r == 1) return pow(3, n / 3 - 1) * 4;
        else return pow(3, n / 3) * 2;
    }
};