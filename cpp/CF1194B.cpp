#include <bits/stdc++.h>
using namespace std;
const int N = 50005, INF = 0x3f3f3f3f;
int a[N], b[N]; char c[400005];
int main()
{
    int q, n, m;
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++) a[i] = 0;
        for (int i = 0; i < m; i++) b[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[i * m + j];
                if (c[i * m + j] == '*') { a[i]++; b[j]++; }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int t = n - a[i] + m - b[j];
                if (c[i * m + j] == '.') t--;
                ans = min(ans, t);
            }
        }
        cout << ans << endl;
    }
    return 0;
}