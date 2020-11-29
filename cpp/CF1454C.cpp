#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x; cin >> n;
        vector<int> a;
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (i == 0 || x != a.back())
            {
                a.push_back(x); cnt[x]++;
            }
        }
        if (cnt.size() == 1) cout << 0 << endl;
        else
        {
            cnt[a[0]]--; cnt[a.back()]--;
            int res = INF;
            for (auto& it: cnt)
            {
                res = min(res, it.second + 1);
            }
            cout << res << endl;
        }
    }
    return 0;
}