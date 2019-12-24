#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) > 1) cout << "Infinite" << endl;
        else cout << "Finite" << endl;
    }
    return 0;
}