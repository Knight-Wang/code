#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int q, x;
    while (cin >> q >> x)
    {
        int y;
        map<int, int> mp;
        set<pair<int, int>> st;
        for (int i = 0; i < x; i++) { mp[i] = 0; st.insert(make_pair(0, i)); }
        for (int i = 0; i < q; i++)
        {
            cin >> y;
            int t = y % x;
            st.insert(make_pair(mp[t] + 1, t));
            mp[t]++;
            while (st.begin()->first < mp[st.begin()->second])
            {
                st.erase(st.begin());
            }
            cout << st.begin()->first * x + st.begin()->second << endl;
        }
    }
    return 0;
}