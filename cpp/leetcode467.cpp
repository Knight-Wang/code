class Solution 
{
public:
    int findSubstringInWraproundString(string p) 
    {
        int n = p.length();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26)
                dp[i] += dp[i - 1];
        }
        unordered_map<int, int> m;
		for (int i = 0; i < 26; i++) m[i] = 0;
        for (int i = 0; i < n; i++)
            m[p[i] - 'a'] = max(m[p[i] - 'a'], dp[i]);
        int sum = 0;
        for (auto it : m) sum += it.second;
        return sum;
    }
};
/*
"zabbc"
*/