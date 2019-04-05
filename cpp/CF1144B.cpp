#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<ll> odd, even;
        ll x;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (x % 2) odd.push_back(x);
            else even.push_back(x);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        ll ans = 0;
        if (odd.size() == even.size()) ans = 0;
        else if (odd.size() > even.size())
        {
            ans = accumulate(odd.begin(), odd.begin() + odd.size() - even.size() - 1, 0);
        }
        else
        {
            ans = accumulate(even.begin(), even.begin() + even.size() - odd.size() - 1, 0);   
        }
        cout << ans << endl;
    }
    return 0;
}