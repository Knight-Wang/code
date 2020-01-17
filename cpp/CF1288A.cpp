#include <bits/stdc++.h>
using namespace std;
int my_ceil(int x, int y)
{
    return (x + y - 1) / y;
}
int main()
{
    int t, n, d; cin >> t;
    while (t--)
    {
        cin >> n >> d;
        bool flg = false;
        for (int i = max(0, (int)sqrt(d) - 5); i <= sqrt(d) + 5; i++)
        {
            if (i + 1 + my_ceil(d, i + 1) - 1 <= n) { flg = true; break; }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}
