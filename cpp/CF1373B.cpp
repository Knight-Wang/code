#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = s.length();
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0') c0++;
            else c1++;
        }
        int t = min(c0, c1);
        string res = (t & 1) ? "DA" : "NET";
        cout << res << endl;
    }
    return 0;
}