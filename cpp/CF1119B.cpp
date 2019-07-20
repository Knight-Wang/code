#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005], b[1005];
bool check(int n, ll h)
{
    for (int i = 1; i <= n; i++) b[i] = a[i];
    sort(b + 1, b + n + 1);
    ll sum = 0;
    for (int i = n; i >= 1; i -= 2) sum += b[i];
    return sum <= h;
}
int main()
{
    int n; ll h;
    while (cin >> n >> h)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = n;
        while (!check(ans, h)) ans--;
        cout << ans << endl;
    }
    return 0;
}