#include <bits/stdc++.h>
using namespace std;
int my_ceil(int x, int y)
{
    return (x + y - 1) / y;
}
int main()
{
    int n;
    while (cin >> n)
    {
        int m = my_ceil(n + 1, 2);
        cout << m << endl;
        for (int i = 1; i <= n / 2; i++) cout << 1 << " " << i << endl;
        for (int i = n / 2 + 1; i <= n; i++) cout << m << " " << m + i - n << endl;
    }
    return 0;
}