#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int l = 1, r = m;
        for (int i = 1; i <= m / 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d %d\n", j, l);
                printf("%d %d\n", n - j + 1, r);
            }
            l++; r--;
        }
        if (m & 1)
        {
            for (int i = 1; i <= n / 2; i++)
            {
                printf("%d %d\n", i, l);
                printf("%d %d\n", n - i + 1, l);
            }
            if (n & 1)
            {
                printf("%d %d\n", n + 1 >> 1, l);
            }
        }
    }
    return 0;
}