#include <bits/stdc++.h>
using namespace std;
int l[105], r[105];
int main()
{
    int n, x;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
        cin >> x;
        int i = 1;
        for ( ; i <= n; i++)
        {
            if (x >= l[i] && x <= r[i]) break;
        }
        cout << n - i + 1 << endl;
    }
    return 0;
}