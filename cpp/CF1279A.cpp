#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        if (v[0] + v[1] < v[2] - 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}