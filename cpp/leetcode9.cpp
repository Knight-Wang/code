class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        long long y = 0, t = x;
        while (x)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y == t;
    }
};