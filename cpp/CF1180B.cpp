#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        int maxn = 0, id = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == 0) a[i] = -1;
            else if (a[i] > 0) a[i] = -a[i] - 1;
            if (abs(a[i]) > maxn) { maxn = abs(a[i]); id = i; }
        }
        if (n & 1)
        {
            if (maxn == 1)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (a[i] == -1) { a[i] = 0; break; } 
                }
            }
            else
            {
                a[id] = -a[id] - 1;
            }
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}