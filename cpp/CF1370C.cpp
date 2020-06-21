#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> fac(ll x)
{
    map<ll, int> res;
    for (ll i = 2; i * i <= x; i++)
    {
        while (x % i == 0) { x /= i; res[i]++; }
    }
    if (x > 1) res[x]++;
    return res;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        if (n == 1) cout << "FastestFinger" << endl;
        else if (n & 1) cout << "Ashishgup" << endl;
        else
        {
            map<ll, int> res = fac(n);
            int t = res.size();
            if (res[2] == 1)
            {
                if (t == 2)
                {
                    int sum = 0;
                    for (auto it: res) sum += it.second;
                    if (sum == 2) cout << "FastestFinger" << endl;
                    else cout << "Ashishgup" << endl;
                }
                else cout << "Ashishgup" << endl;
            }
            else
            {
                if (t == 1) cout << "FastestFinger" << endl;
                else cout << "Ashishgup" << endl;
            }
        }
    }
    return 0;
}