#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = s.length();
        set<char> st;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j + 1 < n && s[j] == s[j + 1]) j++;
            if ((j - i + 1) & 1) st.insert(s[i]);
            i = j;
        }
        for (auto it: st) cout << it;
        cout << endl;
    }
    return 0;
}