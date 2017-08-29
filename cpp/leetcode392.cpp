class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int m = s.length(), n = t.length();
        if (!m) return true;
        int now = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[i] == s[now]) now++;
            if (now == m) return true;
        }
        return false;
    }
};