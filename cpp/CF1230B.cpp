#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, k; string s;
    while (cin >> n >> k)
    {
        cin >> s;
        if (n == 1) { cout << (k >= 1 ? "0" : s) << endl; continue; }
        if (k == 0) { cout << s << endl; continue; }
        if (s[0] > '1') { s[0] = '1'; k--; }
        if (k > 0)
        {
            for (int i = 1; i < n; i++)
            {
                if (s[i] > '0')
                {
                    s[i] = '0'; k--;
                    if (k == 0) break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}