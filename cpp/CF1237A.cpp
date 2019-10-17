#include <bits/stdc++.h>
using namespace std;
int a[20000], b[20000];
int main()
{
    int n;
    while (cin >> n)
    {
        int x = 0;
        for (int i = 0; i < n; i++) { cin >> a[i]; b[i] = a[i] / 2; x += b[i]; }
        if (x > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] < 0 && a[i] % 2 == -1)
                {
                    b[i]--; x--;
                    if (x == 0) break;
                }
            }
        }
        else if (x < 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] > 0 && a[i] % 2 == 1)
                {
                    b[i]++; x++;
                    if (x == 0) break;
                }
            }
        }
        for (int i = 0; i < n; i++) cout << b[i] << endl;
    }
    return 0;
}