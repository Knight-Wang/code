#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n >= 2)
        {
            if (a[0] & 1 && a[1] & 1) cout << "2\n" << 1 << " " << 2 << endl;
            else
            {
                cout << "1\n";
                if (a[0] & 1) cout << 2 << endl;
                else cout << 1 << endl;
            }
        }
        else
        {
            if (a[0] & 1) cout << -1 << endl;
            else cout << "1\n" << 1 << endl;
        }
    }
    return 0;
}