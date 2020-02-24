#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll maxn = 0; int id = 0;
        for (int i = 1; i <= n; i++)
        {
            ll tmp = a[i], up = a[i];
            for (int j = i - 1; j >= 1; j--)
            {
                up = min(a[j], up);
                tmp += up;
            }
            up = a[i];
            for (int j = i + 1; j <= n; j++)
            {
                up = min(a[j], up);
                tmp += up;
            }
            if (tmp > maxn) { maxn = tmp; id = i; }
        }
        for (int j = id - 1; j >= 1; j--)
        {
            a[j] = min(a[j], a[j + 1]);
        }
        for (int j = id + 1; j <= n; j++)
        {
            a[j] = min(a[j], a[j - 1]);
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}