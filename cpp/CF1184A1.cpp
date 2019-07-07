#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long r;
    while (cin >> r)
    {
        if (r < 5 || r % 2 == 0) { cout << "NO" << endl; continue; }
        cout << 1 << " " << (r - 3) / 2 << endl;
    }
    return 0;
}