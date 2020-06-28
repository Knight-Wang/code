#include <bits/stdc++.h>
using namespace std;
int p[1000005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = s.length(), c = 0, minn = 0;
        for (int i = 0; i <= n; i++) p[i] = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+') c++;
            else c--;
            if (c < 0)
            {
                if (p[-c] == -1) p[-c] = i;
                minn = min(minn, c);
            }
        }
        long long res = 0;
        for (int i = 1; i <= -minn; i++) res += p[i] + 1;
        res += n;
        cout << res << endl;
    }
    return 0;
}