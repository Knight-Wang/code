#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int cnt[40];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 0; j <= 30; j++)
            {
                ll msk = 1ll << j;
                if (msk & a[i]) cnt[j]++;
            }
        }
        int i = 30;
        for ( ; i >= 0; i--)
        {
            if (cnt[i] == 1) break;
        }
        if (i != -1)
        {
            int j = 1;
            for ( ; j <= n; j++)
            {
                ll msk = 1ll << i;
                if (msk & a[j]) break;
            }
            swap(a[1], a[j]);
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}