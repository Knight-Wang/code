#include <bits/stdc++.h>
using namespace std;
char a[2005][2005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> t(10, n), b(10, -1), l(10, n), r(10, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                int id = a[i][j] - '0';
                t[id] = min(t[id], i);
                b[id] = max(b[id], i);
                l[id] = min(l[id], j);
                r[id] = max(r[id], j);
            }
        }
        vector<int> res(10, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int id = a[i][j] - '0';
                res[id] = max(res[id], max(i, n - 1 - i)* max(j - l[id], r[id] - j));
                res[id] = max(res[id], max(j, n - 1 - j) * max(i - t[id], b[id] - i));
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    } 
    return 0;
}