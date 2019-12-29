#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], b[100005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        set<int> st;
        ll res = 0; int cur = 1, cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            if (st.count(b[i])) res++;
            else
            {
                while (a[cur] != b[i]) { st.insert(a[cur]); cur++; }
                res += 2 * (cur - cnt - 1) + 1;
            }
            cnt++;
        }
        cout << res << endl;
    }
    return 0;
}