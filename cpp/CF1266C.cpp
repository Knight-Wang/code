#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int main()
{
    int r, c;
    while (cin >> r >> c)
    {
        if (c == 1)
        {
            if (r == 1) cout << 0 << endl;
            else
            {
                for (int i = 1; i <= r; i++)
                {
                    cout << i + 1 << endl;
                }
            }
            continue;
        }
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                a[i][j] = i * (j + r);
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}