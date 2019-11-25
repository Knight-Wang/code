#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], b[N], c[N];
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) a[i] = c[i] = 0;
        for (int i = 1; i <= n; i++) cin >> b[i];
        c[1] = b[1]; a[b[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (b[i] > b[i - 1]) { c[i] = b[i]; a[b[i]] = 1; }
        }
        bool flg = true;
        int j = 1;
        for (int i = 2; i <= n; i++)
        {
            if (c[i] == 0)
            {
                while (j <= n && a[j] == 1) j++;
                if (j > n || j > b[i]) { flg = false; break; }
                else { c[i] = j; a[j] = 1; }
            }
        }
        if (!flg) cout << -1 << endl;
        else
        {
            for (int i = 1; i <= n; i++) cout << c[i] << " ";
            cout << endl;
        }
    }
    return 0;
}