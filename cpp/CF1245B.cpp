#include <bits/stdc++.h>
using namespace std;
int ceil(int x, int y)
{
    return (x + y - 1) / y;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, a, b, c; string s;
        cin >> n >> a >> b >> c >> s;
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'S') x++;
            else if (s[i] == 'R') y++;
            else z++;
        }
        int tot = min(a, x) + min(b, y) + min(c, z);
        if (tot >= ceil(n, 2))
        {
            cout << "YES" << endl;
            vector<char> v(n, 'X');
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'S')
                {
                    if (a) { v[i] = 'R'; a--; }
                    else continue;
                }
                else if (s[i] == 'R')
                {
                    if (b) { v[i] = 'P'; b--; }
                    else continue;
                }
                else
                {
                    if (c) { v[i] = 'S'; c--; }
                    else continue;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (v[i] != 'X') continue;
                if (a) { v[i] = 'R'; a--; }
                else if (b ){ v[i] = 'P'; b--; }
                else { v[i] = 'S'; c--; }
            }
            string res{v.begin(), v.end()};
            cout << res << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}