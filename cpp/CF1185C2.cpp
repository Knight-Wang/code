#include <bits/stdc++.h>
using namespace std;
int a[200005], b[105];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(b, 0, sizeof b);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << 0 << " "; b[a[0]]++;
        for (int i = 1; i < n; i++)
        {
            int maxn = m - a[i];
            int sum = 0, cnt = 0;
            for (int j = 1; j <= 100; j++)
            {
                if (b[j] == 0) continue;
                if (sum + b[j] * j <= maxn) { sum += b[j] * j; cnt += b[j]; }
                else
                {
                    int r = maxn - sum;
                    sum += r / j * j;
                    cnt += r / j;
                    break;
                }
            }
            cout << i - cnt << " ";
            b[a[i]]++;
        }
        cout << endl;
    }
    return 0;
}