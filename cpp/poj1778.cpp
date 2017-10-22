#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005];
int n1, n2;
inline void help(queue<int>& a, queue<int>& b, int x)
{
    if (x > n1) b.push(x);
    else a.push(x);
}
bool same(int x, int y)
{
    if (x >= 1 && x <= n1 && y >= 1 && y <= n1) return true;
    if (x > n1 && y > n1) return true;
    return false;
}
int cal(queue<int> a, queue<int> b, vector<int>in, bool set)
{
    int cnt = 0, last = -1, rnd = 0;
    while (!a.empty() || !b.empty())
    {
        if ((!set && rnd) || set)
        {
            while (!a.empty() && !in[a.front()]) 
            {
                int tmp = a.front(); a.pop();
                if (!same(tmp, last)) cnt++;
                last = tmp;
                for (int i = 0; i < (int)G[tmp].size(); i++)
                {
                    int son = G[tmp][i];
                    if (--in[son] == 0) help(a, b, son);
                }
            }
        }
        while (!b.empty() && !in[b.front()]) 
        {
            int tmp = b.front(); b.pop();
            if (!same(tmp, last)) cnt++;
            last = tmp;
            for (int i = 0; i < (int)G[tmp].size(); i++)
            {
                int son = G[tmp][i];
                if (--in[son] == 0) help(a, b, son);
            }
        }
        rnd++;
    }
    return cnt;
}
int main()
{
    int d, x, y;
    while (~scanf("%d %d %d", &n1, &n2, &d), n1 + n2 + d)
    {
        for (int i = 1; i <= n1 + n2; i++) G[i].clear();
        vector<int> in(n1 + n2 + 1, 0);
        while (d--)
        {
            scanf("%d %d", &x, &y);
            G[y].push_back(x);
            in[x]++;
        }
        queue<int> a, b;
        for (int i = 1; i <= n1 + n2; i++)
        {
            if (!in[i]) help(a, b, i);
        }
        printf("%d\n", min(cal(a, b, in, true), cal(a, b, in, false)) + 1);
    }
    return 0;
}