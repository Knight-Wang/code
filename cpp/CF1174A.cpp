#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= 2 * n; i++) cin >> a[i];
        sort(a + 1, a + 2 * n + 1);
        if (a[1] == a[2 * n]) { cout << -1 << endl; continue; } 
        for (int i = 1; i <= 2 * n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}