#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int q, n; cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int x = 2048;
        bool flg = false;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] > 2048) continue;
            else if (a[i] == 2048) { flg = true; break; }
            else
            {
                x -= a[i];
                if (x <= 0)
                {
                    if (x == 0) flg = true;
                    break;
                }
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}