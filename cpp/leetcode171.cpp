class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int n = (int)s.length(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += s[i] - 'A' + 1;
            if (i != n - 1) ans *= 26;
        }
        return ans;
    }
};