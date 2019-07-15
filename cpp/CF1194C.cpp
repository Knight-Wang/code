#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int q; string s, t, p;
    cin >> q;
    while (q--)
    {
        cin >> s >> t >> p;
        int a = s.length(), b = t.length(), c = p.length();
        int i = 0, j = 0;
        while (i < a && j < b)
        {
            if (s[i] == t[j]) { i++; j++; }
            else j++;
        }
        if (i != a) { cout << "NO" << endl; continue; }
        map<char, int> mp, mp2;
        for (int i = 0; i < b; i++)
        {
            if (!mp.count(t[i])) mp[t[i]] = 0;
            mp[t[i]]++;
        }
        for (int i = 0; i < a; i++) mp[s[i]]--;
        for (int i = 0; i < c; i++)
        {
            if (!mp2.count(p[i])) mp2[p[i]] = 0;
            mp2[p[i]]++;
        }
        bool flg = true;
        for (auto it: mp)
        {
            if (it.second == 0) continue;
            if (!mp2.count(it.first) || mp2[it.first] < it.second) { flg = false; break; }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}