#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main()
{
    ll b, k;
    while (cin >> b >> k)
    {
        for (int i = 0; i < k; i++) cin >> a[i];
        ll ans = 0, d = 1; 
        for (int i = k - 1; i >= 0; i--) { ans += a[i] * d; d *= b; }
        if (ans & 1) cout << "odd" << endl;
        else cout << "even" << endl;
    }
    return 0;
}