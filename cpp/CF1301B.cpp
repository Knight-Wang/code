#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[100005], b[100005], n;
int check(int x)
{
    for (int i = 0; i < n; i++) b[i] = a[i];
    int maxn = 0;
    if (b[0] == -1) b[0] = x;
    for (int i = 1; i < n; i++)
    {
        if (b[i] == -1) b[i] = x;
        maxn = max(maxn, abs(b[i] - b[i - 1]));
    }
    return maxn;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1) continue;
            if (i - 1 >= 0 && a[i - 1] == -1) st.insert(a[i]);
            if (i + 1 < n && a[i + 1] == -1) st.insert(a[i]);
        }
        if (st.empty()) { cout << "0 0\n"; continue; }
        vector<int> v{st.begin(), st.end()};
        int x = (v[0] + v.back()) / 2, y = x + 1;
        int res_x = check(x), res_y = check(y);
        if (res_x < res_y) cout << res_x << " " << x << endl;
        else cout << res_y << " " << y << endl;
    }
    return 0;
}