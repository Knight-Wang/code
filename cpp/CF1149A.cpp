#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, x, y;
    while (cin >> n)
    {
        x = y = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            if (t & 1) x++;
            else y++;
        }
        if (!y)
        {
            while (x) { cout << "1 "; x--; }
            cout << endl;
        }
        else
        {
            cout << "2 "; y--;
            if (x) { cout << "1 "; x--; }
            while (y) { cout << "2 "; y--; }
            while (x) { cout << "1 "; x--; }
            cout << endl;
        }
    }
    return 0;
}