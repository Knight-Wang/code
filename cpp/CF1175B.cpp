#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = (1ll << 32) - 1;
int main()
{
    int l;
    while (cin >> l)
    {
        string s;
        stack<ll> st; st.push(1);
        ll cur = 0, n;
        bool flg = true;
        for (int i = 0; i < l; i++)
        {
            cin >> s;
            if (s == "for")
            {
                cin >> n;
                st.push(min(MAXN + 1, n * st.top()));
            }
            else if (s == "add")
            {
                cur += st.top();
                if (cur > MAXN) flg = false;
            }
            else st.pop();
        }
        if (!flg) cout << "OVERFLOW!!!" << endl;
        else cout << cur << endl;
    }
    return 0;
}