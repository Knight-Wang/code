#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        int res = 0;
        for (int i = 0; i <= min(a, d); i++)
        {
            int j = min(min(b, c), d - i);
            res = max(res, i * e + j * f);
        }
        cout << res << endl;
    }
    return 0;
}