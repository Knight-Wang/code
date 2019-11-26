#include <bits/stdc++.h>
using namespace std;
char a[2][200005];
int main()
{
    int q, n; cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int x = 0, y = 0;
        while (x >= 0 && x <= 1 && y >= 0 && y < n)
        {
            if (x == 0)
            {
                if (a[x][y] == '1' || a[x][y] == '2') y++;
                else if (a[1][y] == '1' || a[1][y] <= '2') break;
                else { x++; y++; }
            }
            else
            {
                if (a[x][y] == '1' || a[x][y] == '2') y++;
                else if (a[0][y] == '1' || a[0][y] == '2') break;
                else { x--; y++; }
            }
        }
        if (x == 1 && y == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}