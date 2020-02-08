#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N][30];
int main()
{
    int n; cin >> n;
    while (n--)
    {
        string s, t;
        cin >> s >> t;
        set<char> st{s.begin(), s.end()};
        bool flg = true;
        for (auto it: t)
        {
            if (!st.count(it)) { flg = false; break; }
        }
        if (!flg) { cout << -1 << endl; continue; }
        int n = s.length(), m = t.length();
        for (int i = 0; i < 26; i++) a[n][i] = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
            {
                a[i][j] = a[i + 1][j];
            }
            a[i][s[i] - 'a'] = i;
        }
        int cur = 0, p = 0, res = 0;
        while (cur < m)
        {
            if (a[p][t[cur] - 'a'] == -1)
            {
                p = a[0][t[cur] - 'a'] + 1;
                res++;
            }
            else p = a[p][t[cur] - 'a'] + 1;
            cur++;
        }
        cout << res + 1 << endl;
    }
    return 0;
}