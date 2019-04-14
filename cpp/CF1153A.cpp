#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, s, d;
    while (cin >> n >> t)
    {
        int minn = 0x3f3f3f3f, ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> d;
            while (s < t) s += d;
            if (s < minn) { minn = s; ans = i + 1; }
        }
        cout << ans << endl;
    }
    return 0;
}