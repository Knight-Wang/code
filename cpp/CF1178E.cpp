#include <bits/stdc++.h>
using namespace std;
int c[3];
int main()
{
    string s;
    while (cin >> s)
    {
        int n = s.length();
        if (n <= 3) { cout << s[0] << endl; continue; }
        int l = 0, r = n - 1; string ans = "";
        while (l + 1 < r - 1)
        {
            memset(c, 0, sizeof c);
            c[s[l] - 'a']++; c[s[l + 1] - 'a']++;
            c[s[r] - 'a']++; c[s[r - 1] - 'a']++;
            for (int i = 0; i < 3; i++)
            {
                if (c[i] == 2) { ans += char('a' + i); break; }
            }
            l += 2; r -= 2;
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if (l <= r) ans += s[l];
        ans += rev;
        cout << ans << endl;
    }
    return 0;
}