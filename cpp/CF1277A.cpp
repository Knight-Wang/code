#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long x; cin >> x;
        string s = to_string(x);
        int n = s.length();
        if (n == 1) { cout << x << endl; continue; }
        int res = (n - 1) * 9;
        int tmp = s[0] - '0';
        int i = 1;
        while (i < n)
        {
            if (s[i] > s[i - 1] || s[i] < s[0]) break;
            i++;
        }
        if (i != n && s[i] < s[0]) tmp--;
        cout << res + tmp << endl;
    }
    return 0;
}