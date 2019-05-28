#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline bool check(string & s, int n, int x, int y)
{
    for (int i = x; i <= y; i++)
    {
        for (int k = 1; i + 2 * k <= y; k++)
        {
            if (s[i] == s[i + k] && s[i] == s[i + 2 * k]) return true;
        }
    }
    return false;
}
int main()
{
    string s;
    while (cin >> s)
    {
        int n = s.length();
        ll ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 2;
            while (j < n && !check(s, n, i, j)) j++;
            ans += n - j;
        }
        cout << ans << endl;
    }
    return 0;
}