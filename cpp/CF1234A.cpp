#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q, n, x;
    cin >> q;
    while (q--)
    {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x; sum += x;
        }
        cout << (sum + n - 1) / n << endl;
    }
    return 0;
}