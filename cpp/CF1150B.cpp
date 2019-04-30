#include <bits/stdc++.h>
using namespace std;

char a[55][55];
int n;

bool ok(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= n && a[i][j] == '.'; 
}

bool check(int i, int j)
{
    if (!ok(i, j)) return false; a[i][j] = '#';
    if (!ok(i + 1, j)) return false; a[i + 1][j] = '#';
    if (!ok(i + 1, j - 1)) return false; a[i + 1][j - 1] = '#';
    if (!ok(i + 1, j + 1)) return false; a[i + 1][j + 1] = '#';
    if (!ok(i + 2, j)) return false; a[i + 2][j] = '#';
    return true;
}

int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        bool flg = true;
        for (int i = 1; i <= n; i++)
        {
            if (!flg) break;
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == '.' && !check(i, j))
                {
                    flg = false; break;
                }
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}