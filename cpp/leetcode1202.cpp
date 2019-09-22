class Solution
{
public:
    void init(vector<int>& p)
    {
        for (int i = 0; i < p.size(); i++) p[i] = i;
    }
    int find(vector<int>& p, int x)
    {
        if (p[x] == x) return x;
        return p[x] = find(p, p[x]);
    }
    void uni(vector<int>& p, int x, int y)
    {
        x = find(p, x); y = find(p, y);
        if (x != y) p[x] = y;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        int n = s.length();
        vector<int> p(n);
        init(p);
        for (auto it: pairs) uni(p, it[0], it[1]);
        vector<vector<int>> res(n, vector<int>());
        vector<vector<char>> res2(n, vector<char>());
        for (int i = 0; i < n; i++)
        {
            int tmp = find(p, i);
            res[tmp].push_back(i);
            res2[tmp].push_back(s[i]);
        }
        for (int i = 0; i < res2.size(); i++) sort(res2[i].begin(), res2[i].end());
        vector<pair<int, char>> res3;
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                res3.push_back(make_pair(res[i][j], res2[i][j]));
            }
        }
        sort(res3.begin(), res3.end());
        string ans = "";
        for (auto it: res3) ans += it.second;
        return ans;
    }
};