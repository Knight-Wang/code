#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        long long s = 0, x = 0, a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            s += a; x ^= a;
        }
        cout << 2 << endl;
        cout << x << " " << x + s << endl;
    }
    return 0;
}