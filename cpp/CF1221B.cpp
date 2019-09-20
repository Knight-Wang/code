#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            int cur = (i & 1) ? 1 : 0;
            for (int j = 0; j < n; j++)
            {
                cout << (cur ? 'B' : 'W');
                cur = 1 - cur;
            }
            cout << endl;
        }
    }
    return 0;
}