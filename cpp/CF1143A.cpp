#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int max0 = -1, max1 = -1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) max0 = i;
            else max1 = i;
        }
        cout << min(max0, max1) << endl;
    }
    return 0;
}