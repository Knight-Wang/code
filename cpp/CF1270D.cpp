#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 1; i <= k + 1; i++) st.insert(i);
    int x, p;
    map<int, int> mp;
    for (int i = 1; i <= k + 1; i++)
    {
        if (i > 1) st.insert(i - 1);
        st.erase(i);
        cout << "? ";
        for (auto it: st) cout << it << " ";
        cout << endl;
        cout.flush();
        cin >> x >> p;
        mp[p]++;
    }
    cout << "! " << mp.rbegin()->second << endl;
    return 0;
}