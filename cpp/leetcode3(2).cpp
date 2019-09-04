class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> p(256, -1);
        int res = 0, dp = 0;
        for (int i = 0; i < n; i++)
        {
            int t = p[s[i]];
            if (t == -1 || i - t > dp) dp++;
            else dp = i - t;
            res = max(res, dp);
            p[s[i]] = i;
        }
        return res;
    }
};