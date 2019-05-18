#include <bits/stdc++.h>
using namespace std;
int a[30];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(a, 0, sizeof a);
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            a[s[0] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i <= 25; i++)
        {
            int x = a[i] / 2, y = a[i] - x;
            ans += x * (x - 1) / 2;
            ans += y * (y - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}