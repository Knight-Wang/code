#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, s;
    while (cin >> n >> s)
    {
        if (s >= 2 * n)
        {
            cout << "YES" << endl;
            int res = 0;
            for (int i = 1; i <= n - 1; i++)
            {
                cout << "2 ";
            }
            cout << s - 2 * n + 2 << endl;
            cout << 1 << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}