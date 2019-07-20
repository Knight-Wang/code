#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int c[N];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> c[i];
        int ans = 0, i = n;
        while (c[i] == c[1]) i--;
        ans = max(ans, i - 1);
        i = 1;
        while (c[i] == c[n]) i++;
        ans = max(ans, n - i);
        cout << ans << endl;
    }
    return 0;
}