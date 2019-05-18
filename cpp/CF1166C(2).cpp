#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int main()
{
    int n;
    while (cin >> n)
    {
        ll ans = 0;
        for (int i = 0; i < n; i++) { cin >> a[i]; a[i] = abs(a[i]); }
        sort(a, a + n);
        int l = 0, r = 0;
        while (l < n)
        {
            while (r < n && a[r] <= 2 * a[l]) r++;
            ans += r - l - 1;
            l++;
        }
        cout << ans << endl;
    }
    return 0;
}