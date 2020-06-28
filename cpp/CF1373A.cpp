#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll a, b, c; cin >> a >> b >> c;
        if (c < a) cout << "-1 1" << endl;
        else if (c == a) cout << "-1 " << b << endl;
        else if (c < a * b) cout << "1 " << b << endl;
        else cout << "1 -1" << endl; 
    }
    return 0;
}