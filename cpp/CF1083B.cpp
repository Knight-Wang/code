#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, k; string a, b;
    while (cin >> n >> k >> a >> b)
    {
        ll ans = 0, cur = 1;
        for (int i = 0; i < n; i++)
        {
            cur <<= 1;
            if (a[i] == 'b') cur--;
            if (b[i] == 'a') cur--;
            if (cur >= k)
            {
                ans += ((ll)n - i) * k;
                break;
            }
            ans += cur;
        }
        cout << ans << endl;
    }
    return 0;
}