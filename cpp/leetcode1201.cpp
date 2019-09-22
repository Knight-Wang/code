class Solution
{
public:
    long long lcm(long long a, long long b)
    {
        return a / __gcd(a, b) * b;
    }
    bool check(long long x, long long n, long long a, long long b, long long c)
    {
        long long tmp = x / a + x / b + x / c;
        tmp -= x / lcm(a, b) + x / lcm(a, c) + x / lcm(b, c);
        tmp += x / lcm(c, lcm(a, b));
        return tmp >= n;
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        long long l = 1, r = 2e9, ans = -1;
        while (l <= r)
        {
            long long m = l + r >> 1;
            if (check(m, n, a, b, c))
            {
                ans = m; r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};