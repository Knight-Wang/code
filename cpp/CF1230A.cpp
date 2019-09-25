#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    while (cin >> a[0] >> a[1] >> a[2] >> a[3])
    {
        int sum = accumulate(a, a + 4, 0);
        bool flg = false;
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (a[i] + a[j] == sum - a[i] - a[j])
                    flg = true;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (a[i] == sum - a[i]) flg = true;
        }
        cout << (flg ? "YES":"NO") << endl;
    }
    return 0;
}