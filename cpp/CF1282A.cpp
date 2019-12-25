#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        if (c < a)
        {
            cout << b - a - min(b - a, max(c + r - a, 0)) << endl;
        }
        else if (a <= c && c <= b)
        {
            cout << max(c - r - a, 0) + max(b - (c + r), 0) << endl;
        }   
        else
        {
            cout << b - a - min(b - a, max(b - (c - r), 0)) << endl;
        }
    }
    return 0;
}