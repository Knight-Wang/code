#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int res = 0, tmp = min(b, c / 2);
        res += tmp * 3;
        b -= tmp;
        res += min(a, b / 2) * 3;
        cout << res << endl;
    }
    return 0;
}