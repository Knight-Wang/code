#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k; ll t;
        cin >> n >> k;
        deque<ll> a; vector<ll> w;
        int cnt = 0;
        for (int i = 0; i < n; i++) { cin >> t; a.push_back(t); } 
        for (int i = 0; i < k; i++)
        {
            cin >> t;
            if (t == 1) cnt++;
            else w.push_back(t);
        }
        sort(a.begin(), a.end());
        sort(w.begin(), w.end());
        ll res = 0;
        for (int i = 0; i < cnt; i++)
        {
            res += a.back() * 2; a.pop_back();
        }
        for (int i = w.size() - 1; i >= 0; i--)
        {
            res += a.back(); a.pop_back();
            res += a.front();
            for (int j = 0; j < w[i] - 1; j++) a.pop_front();
        }
        cout << res << endl;
    }
    return 0;
}