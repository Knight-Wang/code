#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    while (n--)
    {
        string s, c;
        cin >> s >> c;
        if (s < c) { cout << s << endl; continue; }
        string t = s;
        sort(t.begin(), t.end());
        int n = s.length();
        bool flg = false;
        for (int i = 0; i < n; i++)
        {
            if (flg) break;
            if (s[i] != t[i])
            {
                for (int j = n - 1; j > i; j--)
                {
                    if (s[j] == t[i])
                    {
                        swap(s[i], s[j]); flg = true; break;
                    }
                }
            }
        }
        if (s < c) cout << s << endl;
        else cout << "---" << endl;
    }
    return 0;
}