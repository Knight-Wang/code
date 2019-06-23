#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int i = 2, last = 1;
        while (i <= n && a[i] == a[i - 1]) i++;
        int cnt = i - last, ans = 0;
        last = i; i++;
        while (i <= n)
        {
            while (i <= n && a[i] == a[i - 1]) i++;
            ans = max(ans, min(cnt, i - last));
            cnt = i - last; last = i; i++;
        }
        ans = max(ans, min(cnt, i - last));
        cout << 2 * ans << endl;
    }
    return 0;
}