class Solution
{
public:
    
    struct node
    {
        int d, p, s;
        bool operator < (const node& b)const
        {
            return d > b.d;
        }
    };

    int log2(int x)
    {
        return log(x) / log(2);
    }

    struct hash_pair
    {
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const
        { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        }
    };

    int racecar(int target)
    {
        unordered_map<pair<int, int>, int, hash_pair> mp;
        priority_queue<node> q;
        mp[make_pair(0, 1)] = 0;
        q.push(node{log2(target), 0, 1});
        int res = -1;
        while (!q.empty())
        {
            node tmp = q.top(); q.pop();
            pair<int, int> t(tmp.p, tmp.s);
            if (tmp.p == target) { res = mp[t]; break; }
            int np = tmp.p + tmp.s; 
            if (np <= 2 * target && np >= -2 * target)
            {
                pair<int, int> next(np, tmp.s * 2);
                if (!mp.count(next))
                {
                    mp[next] = mp[t] + 1;
                    int g = log2(abs(target - np) / (abs(tmp.s) * 2));
                    q.push(node{mp[next] + g, np, tmp.s * 2});
                }
            }
            int ns = tmp.s > 0 ? -1 : 1;
            pair<int, int> next2(tmp.p, ns);
            if (!mp.count(next2))
            {
                mp[next2] = mp[t] + 1;
                int g = log2(abs(target - tmp.p));
                q.push(node{mp[next2] + g, tmp.p, ns});
            }
        }
        return res;
    }
};