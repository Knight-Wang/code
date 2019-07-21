#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int main()
{
    int w, h;
    while (cin >> w >> h)
    {
        ll ans = 1;
        for (int i = 0; i < w; i++) ans = ans * 2 % MOD;
        for (int i = 0; i < h; i++) ans = ans * 2 % MOD;
        cout << ans << endl;
    }   
    return 0;
}