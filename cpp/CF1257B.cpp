#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int x, y; cin >> x >> y;
        if (x == 1)
        {
            cout << (y == 1 ? "YES": "NO") << endl;
        }
        else if (x == 2 || x == 3)
        {
            cout << (y <= 3 ? "YES" : "NO") << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}