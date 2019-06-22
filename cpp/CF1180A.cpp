#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int ans = 1, tmp = 4;
        for (int i = 1; i <  n; i++) { ans += tmp; tmp += 4; }
        cout << ans << endl;
    }
    return 0;
}