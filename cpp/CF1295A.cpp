#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int x = n / 2, y = 0;
        if (n & 1) { x--; y++; }
        if (y) cout << 7;
        for (int i = 0; i < x; i++) cout << 1;
        cout << endl;
    }
    return 0;
}