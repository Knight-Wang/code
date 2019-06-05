#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == b) cout << a + b + 2 * c << endl;
        else cout << min(a, b) * 2 + 2 * c + 1 << endl;
    }
    return 0;
}