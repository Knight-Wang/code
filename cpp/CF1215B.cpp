#include <bits/stdc++.h>
using namespace std;
long long sign(long long x)
{
    return x > 0 ? 1 : -1;
}
int main()
{
    int n;
    while (cin >> n)
    {
        long long a = 0, b = 0, cn = 0, cp = 0, cur = 1, x;
        for (int i = 0; i < n; i++)
        {
            cin >> x; cur *= sign(x);
            if (cur < 0)
            {
                a += cn; b += cp;
            }
            else
            {
                a += cp; b += cn;
            }
            if (cur > 0) { cp++; a++; }
            else { cn++; b++; }
        }
        cout << b << " "  << a << endl;
    }
    return 0;
}