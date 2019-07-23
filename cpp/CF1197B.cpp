#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        bool flg = true;
        for (int i = 1; i <= n - 2; i++)
        {
            if (a[i + 1] < a[i] && a[i + 2] > a[i + 1]) { flg = false; break; }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}