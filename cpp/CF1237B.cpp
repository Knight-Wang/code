#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        map<int, int> mp;
        for (int i = 1; i <= n; i++) { cin >> a[i]; mp[a[i]] = n - i + 1; }
        set<int> st;
        for (int i = 1; i <= n; i++) { cin >> b[i]; b[i] = mp[b[i]]; st.insert(b[i]); }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            st.erase(b[i]);
            if (*st.rbegin() > b[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}