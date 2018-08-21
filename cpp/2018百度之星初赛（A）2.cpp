#include <bits/stdc++.h>
using namespace std;

list<int> a[150005];

int main()
{
    int n, q, t, u, v, w;
    while (scanf("%d %d", &n, &q) != EOF)
    {
        for (int i = 1; i <= n; i++) a[i].clear();
        while (q--)
        {
            scanf("%d", &t);
            if (t == 1)
            {
                scanf("%d%d%d", &u, &w, &v);
                if (w == 0) a[u].push_front(v);
                else a[u].push_back(v);
            }
            else if (t == 2)
            {
                scanf("%d%d", &u, &w);
                int ans;
                if (a[u].empty()) ans = -1;
                else if (w == 0)
                {              
                    ans = a[u].front(); a[u].pop_front();
                }
                else
                {
                    ans = a[u].back(); a[u].pop_back();
                }
                printf("%d\n", ans);
            }
            else
            {
                scanf("%d%d%d", &u, &v, &w);
                if (w == 1) a[v].reverse();
                a[u].splice(a[u].end(), a[v]);
            }
        }
    }
    return 0;
}