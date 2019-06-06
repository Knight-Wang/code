#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int a[N][N], b[N][N];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> b[i][j];
        bool flg = true;
        for (int i = 0; i < n + m - 1; i++)
        {
            int x, y;
            if (i < n) { x = i; y = 0; }
            else { x = n - 1; y = i - n + 1; }
            vector<int> v1, v2;
            while (x >= 0 && y < m)
            {
                v1.push_back(a[x][y]);
                v2.push_back(b[x][y]);
                x--; y++;
            }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            for (int i = 0; i < v1.size(); i++)
            {
                if (v1[i] != v2[i]) { flg = false; break; }
            }
            if (!flg) break;
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}