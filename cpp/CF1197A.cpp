#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N];
int main()
{
    int T, n; cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << min(a[n - 1] - 1, n - 2) << endl;
    }
    return 0;
}