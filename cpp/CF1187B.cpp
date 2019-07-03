#include <bits/stdc++.h>
using namespace std;
int a[30][200005], b[30];
int main()
{
    int n, m; string s, t;
    while (cin >> n >> s)
    {
        a[s[0] - 'a'][0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                a[j][i] = a[j][i - 1];
            }
            a[s[i] - 'a'][i]++;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> t;
            memset(b, 0, sizeof b);
            for (int j = 0; j < t.length(); j++)
            {
                b[t[j] - 'a']++;
            }
            int maxn = 0;
            for (int j = 0; j < 26; j++)
            {
                int t = lower_bound(a[j], a[j] + n, b[j]) - a[j];
                maxn = max(maxn, t);
            }
            cout << maxn + 1 << endl;
        }
    }
    return 0;
}