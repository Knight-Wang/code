#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b, c, d, x;
    while (cin >> n >> m)
    {
        a = b = c = d = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x & 1) a++;
            else b++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            if (x & 1) d++;
            else c++;
        }
        cout << min(a, c) + min(b, d) << endl; 
    }
    return 0;
}