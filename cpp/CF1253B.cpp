#include <bits/stdc++.h>
using namespace std;
int a[100005], b[1000005];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(b, 0, sizeof b);
        bool flg = true;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < 0)
            {
                if (b[-a[i]] == 0) { flg = false; break; }
                else b[-a[i]]--;
            }
            else
            {
                if (b[a[i]] == 1) { flg = false; break; }
                else b[a[i]]++;
            }
        }
        for (int i = 1; i <= 1000000; i++)
        {
            if (b[i]) { flg = false; break; }
        }
        if (!flg) { cout << -1 << endl; continue; }
        vector<int> v; int cnt = 0, last = 1;
        set<int> st;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
            {
                if (st.count(a[i])) { flg = false; break; }
                else cnt++;
            }
            else
            {
                cnt--;
                st.insert(-a[i]);
                if (cnt == 0) { v.push_back(i - last + 1); last = i + 1; st.clear(); }
            }
        }
        if (!flg) cout << -1 << endl;
        else
        {
            cout << v.size() << endl;
            for (auto it: v) cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}