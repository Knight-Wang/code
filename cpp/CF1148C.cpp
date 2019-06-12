#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int a[N], p[N], n;
inline void work(int i, int j, vector<pair<int, int>> & ans)
{
    swap(a[i], a[j]);
    p[a[i]] = i;
    p[a[j]] = j;
    ans.push_back(make_pair(i, j));
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); p[a[i]] = i; }
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == i) continue;
            int t = p[i];
            if (abs(t - i) >= n / 2)
            {
                work(i, t, v);
            }
            else if (i - 1 >= n / 2 && t - 1 >= n / 2)
            {
                work(i, 1, v);
                work(1, t, v);
                work(i, 1, v);
            }
            else if (n - i >= n / 2 && n - t >= n / 2)
            {
                work(i, n, v);
                work(n, t, v);
                work(i, n, v);
            }
            else
            {
                if (i - 1 >= n / 2)
                {
                    work(i, 1, v);
                    work(t, n, v);
                    work(1, n, v);
                    work(i, 1, v);
                    work(t, n, v);
                }
                else
                {
                    work(i, n, v);
                    work(t, 1, v);
                    work(1, n, v);
                    work(i, n, v);
                    work(t, 1, v);
                }
            }
        }
        printf("%d\n", v.size());
        for (auto it: v) printf("%d %d\n", it.first, it.second);
    }
    return 0;
}