#include <bits/stdc++.h>
using namespace std;
bool check(int x)
{
    set<int> st;
    string tmp = to_string(x);
    for (int i = 0; i < tmp.length(); i++)
    {
        if (st.count(tmp[i])) return false;
        st.insert(tmp[i]);
    }
    return true;
}
int main()
{
    int l, r;
    while (cin >> l >> r)
    {
        int ans = -1;
        for (int i = l; i <= r; i++)
        {
            if (check(i)) { ans = i; break; }
        }
        cout << ans << endl;
    }
    return 0;
}