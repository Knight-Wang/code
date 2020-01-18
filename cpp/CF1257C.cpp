#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> a[200005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            a[x].push_back(i);
        }
        int ans = INF;
        for (int i = 1; i <= n; i++)
        {
            int m = a[i].size();
            for (int j = 0; j < m - 1; j++)
            {
                ans = min(ans, a[i][j + 1] - a[i][j] + 1);
            }
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}