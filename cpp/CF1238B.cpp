#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t, n, r, x; cin >> t;
    while (t--)
    {
        cin >> n >> r;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            cin >> x; v.push_back(x);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int ans = 0;
        int i = v.size() - 1;
        while (i >= 0)
        {
            if (v[i] - ans * r <= 0) break;
            ans++;
            i--;
        }
        cout << ans << endl;
    }
    return 0;
}