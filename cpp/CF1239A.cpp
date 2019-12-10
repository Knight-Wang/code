#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a[100005];
int main()
{
    a[1] = 1; a[2] = 2;
    for (int i = 3; i <= 100000; i++) a[i] = (a[i - 1] + a[i - 2]) % MOD;
    int n, m;
    while (cin >> n >> m)
    {
        cout << (a[n] + a[m] - 1) % MOD * 2 % MOD << endl;
    }
    return 0;
}