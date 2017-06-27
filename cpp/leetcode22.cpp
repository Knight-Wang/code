class Solution 
{
public:
    vector<string> ans;
    string buf;
    void dfs(int now, int l, int t, int n)
    {
        if (now == 2 * n)
        {
            ans.push_back(buf);
            return;
        }
        if (l) 
        {
            buf[now] = ')';
            dfs(now + 1, l - 1, t, n);
            if (t < n)
            {
                buf[now] = '(';
                dfs(now + 1, l + 1, t + 1, n);
            }
        }
        else
        {
            buf[now] = '(';
            dfs(now + 1, l + 1, t + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        for (int i = 0; i < 2 * n; i++) buf += ' ';
        dfs(0, 0, 0, n);
        return ans;
    }
};