class Solution
{
public:
    vector<int> p;
    void init(int n)
    {
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;
    }
    int find(int x)
    {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void uni(int x, int y)
    {
        x = find(x); y = find(y);
        if (x == y) return;
        p[x] = y;
    }
    int largestComponentSize(vector<int>& A)
    {
        int maxn = *max_element(A.begin(), A.end());
        init(maxn);
        for (auto it: A)
        {
            vector<int> tmp;
            int x = it;
            for (int i = 2; i * i <= it; i++)
            {
                if (x % i == 0) tmp.push_back(i);
                while (x % i == 0) x /= i;
            }
            if (x != 1) tmp.push_back(x);
            if (tmp.empty()) continue;
            uni(it, tmp[0]);
            for (int i = 0; i < (int)tmp.size() - 1; i++)
                uni(tmp[i], tmp[i + 1]);
        }
        map<int, int> mp;
        for (auto it: A)
        {
            int t = find(it);
            if (!mp.count(t)) mp[t] = 0;
            mp[t]++;
        }
        int res = 0;
        for (auto it: mp) res = max(res, it.second);
        return res;
    }
};