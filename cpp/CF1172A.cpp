#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int b[N];
int main()
{
    int n, x;
    while (cin >> n)
    {
        set<int> st;
        for (int i = 1; i <= n; i++) { cin >> x; st.insert(x); }
        int p = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (b[i] == 1) p = i;
        }
        if (p)
        {
            bool flg = true;
            for (int i = p; i <= n; i++)
            {
                if (b[i] != i - p + 1) { flg = false; break; }
            }
            if (flg)
            {
                int cur = 1;
                for (int i = n - p + 2; i <= n; i++)
                {
                    if (!st.count(i)) { flg = false; break; }
                    st.insert(b[cur++]);
                }
                if (flg) { cout << p - 1 << endl; continue; }
            }
        }
        int maxn = 1;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == 0) continue;
            maxn = max(maxn, i - b[i] + 2);
        }
        cout << n + maxn - 1 << endl;
    }
    return 0;
}