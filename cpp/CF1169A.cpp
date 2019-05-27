#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, x, b, y;
    while (cin >> n >> a >> x >> b >> y)
    {
        bool flg = false;
        while (true)
        {
            if (a == b) { flg = true; break; }
            if (a == x || b == y) break;
            a++;
            if (a == n + 1) a = 1;
            b--;
            if (b == 0) b = n;
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}