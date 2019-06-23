#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int c[N], a[N], b[4], d[4], t[N];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(b, 0, sizeof b);
        char x;
        for (int i = 1; i <= n; i++) { cin >> x; c[i] = x - '0'; }
        for (int i = 1; i <= n; i++) { cin >> x; a[i] = x - '0'; }
        for (int i = 1; i <= n; i++)
        {
            t[i] = c[i] * 2 + a[i];
            b[t[i]]++;
        }
        bool flg = false;
        for (int i = 0; i <= b[0]; i++)
        {
            if (flg) break;
            for (int j = 0; j <= b[1]; j++)
            {
                int x = n / 2 - i - j;
                int y = b[1] + b[3] - j;
                int l = y - x;
                int k = n / 2 - l - i - j;
                if (k >= 0 && k <= b[2] && l >= 0 && l <= b[3])
                {
                    d[0] = i; d[1] = j; d[2] = k; d[3] = l;
                    for (int i = 1; i <= n; i++)
                    {
                        if (d[t[i]])
                        {
                            cout << i << " "; d[t[i]]--;
                        }
                    }
                    cout << endl;
                    flg = true; break;
                }
            }
        }
        if (!flg) cout << -1 << endl;
    }
    return 0;
}