#include <bits/stdc++.h>
using namespace std;
int my_ceil(int x, int y)
{
    return (x + y - 1) / y;
}
int main()
{
    int T, a;
    cin >> T;
    while (T--)
    {
        cin >> a;
        int lb = my_ceil(2 * a, 180 - a);
        lb = max(lb, my_ceil(a, 60));
        int g = __gcd(180, a);
        int ans = 180 / g;
        a /= g;
        if (lb > a) ans *= my_ceil(lb, a);
        cout << ans << endl;
    }
    return 0;
}