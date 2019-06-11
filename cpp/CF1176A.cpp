#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int q; ll n;
    cin >> q;
    while (q--)
    {
        cin >> n;
        ll cnt = 0;
        bool flg = true;
        while (n != 1)
        {
            if (n % 2 == 0) n /= 2;
            else if (n % 3 == 0) n = n * 2 / 3;
            else if (n % 5 == 0) n = n * 4 / 5;
            else { flg = false; break; }
            cnt++;
        }
        if (flg) cout << cnt << endl;
        else cout << -1 << endl;
    }
    return 0;
}