#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long n, a, b; cin >> n >> a >> b;
        if (n == 1) { cout << "1 1\n"; continue; }
        cout << min(n, max(1ll, a + b - n + 1)) << " " << min(a + b - 1, n) << endl;
    }
    return 0;
}