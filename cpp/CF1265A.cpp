#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; string s;
    while (cin >> t)
    {
        for (int i = 0; i < t; i++)
        {
            cin >> s;
            int n = s.length();
            bool flg = true;
            for (int j = 0; j < n - 1; j++)
            {
                if (s[j] != '?' && s[j] == s[j + 1])
                {
                    flg = false; break;
                }
            }
            if (!flg) { cout << -1 << endl; continue; }
            for (int j = 0; j < n; j++)
            {
                if (s[j] == '?')
                {
                    set<int> st;
                    if (j - 1 >= 0) st.insert(s[j - 1]);
                    if (j + 1 < n && s[j + 1] != '?') st.insert(s[j + 1]);
                    char x = 'a';
                    while (x <= 'c')
                    {
                        if (!st.count(x)) break;
                        x++;
                    }
                    s[j] = x;
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}