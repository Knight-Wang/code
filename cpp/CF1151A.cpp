#include <bits/stdc++.h>
using namespace std;

const char a[] = {'A', 'C', 'T', 'G'};

int cost(string s)
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        char x = min(a[i], s[i]), y = max(a[i], s[i]);
        res += min(y - x, x - 'A' + 'Z' - y + 1);
    }
    return res;
}
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n - 3; i++)
        {
            ans = min(ans, cost(s.substr(i, 4)));
        }
        cout << ans << endl;
    }
    return 0;
}