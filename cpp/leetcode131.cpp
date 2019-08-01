class Solution
{
public:

    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        if (n == 0) return vector<vector<string>>();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (j == i) dp[i][j] = true;
                else if (j == i + 1) dp[i][j] = s[i] == s[j];
                else if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;
            }
        }
        unordered_map<int, vector<vector<string>>> mp;
        mp[n] = vector<vector<string>>(1, vector<string>(1, ""));
        for (int i = n - 1; i >= 0; i--)
        {
            vector<vector<string>> v;
            for (int j = i; j < n; j++)
            {
                if (dp[i][j] && mp.count(j + 1))
                {
                    for (auto it: mp[j + 1])
                    {
                        vector<string> x(1, s.substr(i, j - i + 1));
                        auto e = it.end();
                        if (j + 1 == n) e--;
                        x.insert(x.end(), it.begin(), e);
                        v.push_back(x);
                    }
                }
            }
            if (!v.empty()) mp[i] = v;
        }
        if (mp.count(0)) return mp[0];
        return vector<vector<string>>();
    }
};