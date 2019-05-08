#include <bits/stdc++.h>
using namespace std;

int euler(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res = res / n * (n - 1);
    return res;
}  

int main()
{
    int n;
    while (cin >> n)
    {
        cout << (n == 1 ? 1 : (long long)euler(n) * n / 2) << endl;
    }
    return 0;
}