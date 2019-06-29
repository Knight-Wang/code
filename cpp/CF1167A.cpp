#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n; string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        if (n < 11) { cout << "NO" << endl; continue; }
        bool flg = false;
        for (int i = 0; i <= n - 11; i++)
        {
            if (s[i] == '8') { flg = true; break; }
        }
        cout << (flg ? "YES":"NO") << endl;
    }
    return 0;
}