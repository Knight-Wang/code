#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q; cin >> q;
    string s, t;
    while (q--)
    {
        cin >> s >> t;
        set<int> a;
        for (int i = 0; i < s.length(); i++) a.insert(s[i]);
        bool flg = false;
        for (int i = 0; i < t.length(); i++)
        {
            if (a.count(t[i])) { flg = true; break; }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}