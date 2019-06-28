#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int n = a.length(), m = b.length();
        int ans = 0, x = 0, y = 0;
        for (int i = 0; i < m; i++)
        {
            if (b[i] == '1') x++;
        }
        for (int i = 0; i < m; i++)
        {
            if (a[i] == '1') y++;
        }
        if ((x + y) % 2 == 0) ans++;
        for (int i = m; i < n; i++)
        {
            y += (a[i] == '1'); y -= (a[i - m] == '1');
            if ((x + y) % 2 == 0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}