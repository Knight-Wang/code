#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b, c; cin >> a >> b >> c;
        int res = 0;
        if (a) { a--; res++; }
        if (b) { b--; res++; }
        if (c) { c--; res++; }
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        if (v[0] && v[2]) { v[0]--; v[2]--; res++; }
        if (v[1] && v[2]) { v[1]--; v[2]--; res++; }
        if (v[0] && v[1]) { v[0]--; v[1]--; res++; }
        if (v[0] && v[1] && v[2]) res++;
        cout << res << endl;
    }
    return 0;
}