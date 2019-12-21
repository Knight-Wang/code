#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], b[N];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) { cin >> b[i]; b[i] -= a[i]; }
        set<int> st;
        bool flg = true;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] < 0) flg = false;
            else if (b[i]) st.insert(b[i]);
        }
        if (!flg || st.size() > 1) { cout << "NO" << endl; continue; }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!b[i]) continue;
            cnt++;
            int j = i;
            while (j + 1 <= n && b[j + 1] == b[j]) j++;
            i = j;
        }
        cout << (cnt <= 1 ? "YES" : "NO") << endl;
    }
    return 0;
}