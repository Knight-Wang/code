#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == '0') i++;
        int j = n - 1;
        while (j >= 0 && s[j] == '0') j--;
        if (i > j) { cout << 0 << endl; continue; }
        int res = 0;
        s = s.substr(i, j - i + 1);
        n = j - i + 1; i = 0;
        while (i < n)
        {
            while (i < n && s[i] == '1') i++;
            while (i < n && s[i] == '0') { i++; res++; }
        }
        cout << res << endl;
    }
    return 0;
}