#include <bits/stdc++.h>
using namespace std;

bool check(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10; x /= 10;
    }
    return sum % 4 == 0;
}
int main()
{
    int n;
    while (cin >> n)
    {
        while (!check(n)) n++;
        cout << n << endl;
    }
    return 0;
}