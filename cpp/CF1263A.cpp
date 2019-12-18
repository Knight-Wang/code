#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        if (a[0] + a[1] <= a[2]) cout << a[0] + a[1] << endl;
        else cout << (a[0] + a[1] + a[2]) / 2 << endl;
    }
    return 0;
}