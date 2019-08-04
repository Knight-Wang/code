#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[N], b[N];

int main()
{
    int T, n, q, p, v; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cin >> n >> q;
        set<int> st;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; b[i] = 0;
            if (__builtin_popcount(a[i]) & 1) { cnt++; b[i] = 1; st.insert(i); }
        }
        for (int i = 0; i < q; i++)
        {
            cin >> p >> v;
            int t = __builtin_popcount(v) % 2;
            if (t != b[p])
            {
                cnt++;
                if (t == 1 && b[p] == 0) st.insert(p);
                else st.erase(p);
            }
            if (cnt & 1)
            {
                int x = *st.begin(), y = *st.rbegin();
                cout << max(y, n - x - 1);
            }
            else cout << n;
            cout << " ";
            b[p] = t; 
        }
        cout << endl;
    }
    return 0;
}