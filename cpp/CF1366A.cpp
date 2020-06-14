#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; ll a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (2 * b < a) cout << b << endl;
        else if (2 * a < b) cout << a << endl;
        else cout << (a + b) / 3 << endl;
    }
    return 0;
}