#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q, n; cin >> q;
    while (q--)
    {
        cin >> n;
        if (n < 4) cout << 4 - n << endl;
        else cout << (n & 1) << endl;
    }
    return 0;
}