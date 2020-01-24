#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, a, b, c; cin >> a >> b >> c >> n;
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        int tmp = v[2] - v[0] + v[2] - v[1];
        if (n < tmp) cout << "NO" << endl;
        else if ((n - tmp) % 3 != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}