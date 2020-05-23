#include <bits/stdc++.h>
using namespace std;
int a[200005];
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (a[j] <= j - i + 1) { i = j; cnt++; break; }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}