#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    while (cin >> n)
    {
        map<int, int> mp;
        multiset<int> st;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (!mp.count(x)) { mp[x] = 1; st.insert(1); }
            else
            {
                mp[x]++;
                auto t = st.lower_bound(mp[x] - 1);
                st.erase(t);
                st.insert(mp[x]);
            }
            if (mp.size() == 1) { ans = i; continue; }
            auto it = st.rbegin();
            auto it1 = it; it1++;
            if (mp.size() == 2)
            {
                if (*it == *it1 + 1 || *it1 == 1) { ans = i; continue; }
            }
            if (*it == *it1 + 1)
            {
                if (*st.begin() == *it1) ans = i;
            }
            else if (*it == *it1)
            {
                auto it2 = st.begin();
                it2++;
                if (*st.begin() == 1 && *it2 == *it1) ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}