class Solution
{
public:
    int find(int x, vector<int>& p)
    {
        if (p[x] == x) return x;
        return p[x] = find(p[x], p);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) p[i] = i;
        int cnt = n, used = 0;
        for (auto& it: edges)
        {
            if (it[0] != 3) continue;
            int x = find(it[1], p), y = find(it[2], p);
            if (x != y)
            {
                p[x] = y;
                used++;
                cnt--;
                if (cnt == 1) break;
            }
        }
        vector<int> p1 = p; int cnt1 = cnt;
        for (auto& it: edges)
        {
            if (it[0] != 1) continue;
            int x = find(it[1], p), y = find(it[2], p);
            if (x != y)
            {
                p[x] = y;
                used++;
                cnt--;
                if (cnt == 1) break;
            }
        }
        if (cnt != 1) return -1;
        for (auto& it: edges)
        {
            if (it[0] != 2) continue;
            int x = find(it[1], p1), y = find(it[2], p1);
            if (x != y)
            {
                p1[x] = y;
                used++;
                cnt1--;
                if (cnt1 == 1) break;
            }
        }
        if (cnt1 != 1) return -1;
        return edges.size() - used;
    }
};
