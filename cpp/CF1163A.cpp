#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (!m) cout << 1 << endl;
        else if (m <= n / 2) cout << m << endl;
        else cout << n - m << endl;
    }
    return 0;
}