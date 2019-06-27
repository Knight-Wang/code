#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int c[200005];
int main()
{
    int q, n, x;
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) c[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x; c[x]++;
        }
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            if (c[i]) v.push_back(c[i]);
        }
        sort(v.begin(), v.end());
        int ans = v.back(), cur = v.back();
        for (int i = v.size() - 2; i >= 0; i--)
        {
            if (v[i] >= cur) cur--;
            else cur = v[i];
            ans += cur;
            if (cur == 0) break;
        }
        cout << ans << endl;
    }
    return 0;
}