#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        k = min(k - 1, n - k);
        cout << 3 * n + k << endl;
    }
    return 0;
}