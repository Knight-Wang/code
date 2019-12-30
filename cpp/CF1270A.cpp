#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k1, k2, x; cin >> n >> k1 >> k2;
        bool flg = false;
        for (int i = 0; i < k1; i++)
        {
            cin >> x;
            if (x == n) flg = true;
        }
        for (int i = 0; i < k2; i++) cin >> x;
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}