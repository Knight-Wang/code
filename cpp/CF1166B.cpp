#include <bits/stdc++.h>
using namespace std;
const char w[] = {'a','e','i','o','u'};
int main()
{
    int k;
    while (cin >> k)
    {
        bool flg = true;
        for (int i = 5; i < k / 5 + 2; i++)
        {
            if (k % i) continue;
            int j = k / i;
            if (i >= 5 && j >= 5)
            {
                for (int ii = 0; ii < i; ii++)
                {
                    for (int jj = 0; jj < j; jj++)
                    {
                        cout << w[(ii + jj) % 5];
                    }
                }
                cout << endl;
                flg = false; break;
            }
        }
        if (flg) cout << -1 << endl;
    }
    return 0;
}