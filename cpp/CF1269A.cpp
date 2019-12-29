#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 1) cout << "10 9\n";
        else cout << 4 * n << " " << 3 * n << '\n';
    }
    return 0;
}