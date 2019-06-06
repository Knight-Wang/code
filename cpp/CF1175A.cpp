#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    ll n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll cnt = 0;
        while (n)
        {
            if (n % k == 0) { n /= k; cnt++; }
            else { ll r = n % k; n -= r; cnt += r; }
        }
        cout << cnt << endl;
    }
    return 0;
}