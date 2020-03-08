#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        if (n & 1) { cout << -1 << endl; continue; }
        int c = 0, last = -1, res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') c++;
            else c--;
            if (c == 0)
            {
                if (s[i] == '(') res += i - last;
                last = i;
            }
        }
        if (c != 0) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}