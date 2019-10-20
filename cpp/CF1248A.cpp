#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, x, n, m; cin >> t;
    while (t--)
    {
        cin >> n;
        long long a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x & 1) a++;
            else b++;
        }
        long long c = 0, d = 0;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            if (x & 1) c++;
            else d++;
        }
        cout << a * c + b * d << endl;
    }
    return 0;
}