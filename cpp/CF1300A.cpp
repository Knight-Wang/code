#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int c = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x; s += x;
            if (!x) c++;
        }
        if (s + c == 0) cout << c + 1 << endl;
        else cout << c << endl;
    }
    return 0;
}