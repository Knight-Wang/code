class Solution
{
public:
    bool check(vector<int>& a, vector<int>& b)
    {
        for (int i = 0; i < 128; i++)
        {
            if (a[i] < b[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<int> a(128, 0), b(128, 0);
        for (int i = 0; i < n; i++) a[s[i]]++;
        for (int i = 0; i < m; i++) b[t[i]]++;
        if (!check(a, b)) return "";
        for (int i = 0; i < 128; i++) a[i] = 0;
        int i = 0;
        string ans = s;
        for (int j = 0; j < n; j++)
        {
            a[s[j]]++;
            while (i <= j && check(a, b))
            {
                if (j - i + 1 < ans.length()) ans = s.substr(i, j - i + 1);
                a[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};