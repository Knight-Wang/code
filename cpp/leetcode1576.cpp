class Solution
{
public:
    string modifyString(string s)
    {
        int n = s.length();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                for (int j = 0; j < 26; j++)
                {
                    char c = char('a' + j);
                    if (i - 1 >= 0 && c == res[i - 1]) continue;
                    if (i + 1 < n && c == s[i + 1]) continue;
                    res += c;
                    break;
                }
            }
            else res += s[i];
        }
        return res;
    }
};