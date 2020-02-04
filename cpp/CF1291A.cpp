#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; string s; cin >> n >> s;
        int o = 0, e = 0;
        for (int i = 0; i < n; i++)
        {
            int t = s[i] - '0';
            if (t & 1) o++;
            else e++;
        }
        if (o <= 1) cout << -1 << endl;
        else
        {
            int i = n - 1;
            while (i >= 0 && int(s[i] - '0') % 2 == 0) i--;
            if (o & 1)
            {
                int j = i - 1;
                while (j >= 0 && int(s[j] - '0') % 2 == 0) j--;
                s = s.substr(0, j + 1);
            }
            else s = s.substr(0, i + 1);
            if (s.empty()) cout << -1 << endl;
            else cout << s << endl;
        }

    }
    return 0;
}