#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; string s;
        cin >> n >> s;
        int b = -1;
        while (b + 1 < n && s[b + 1] == '0') b++;
        int e = n;
        while (e - 1 >= 0 && s[e - 1] == '1') e--;
        if (b >= 0) cout << s.substr(0, b + 1);
        if (b + 1 != e) cout << 0;
        if (e <= n - 1) cout << s.substr(e, n - e);
        cout << endl;
    }
    return 0;
}