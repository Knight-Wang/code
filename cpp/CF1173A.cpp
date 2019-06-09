#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a > b)
        {
            if (c >= a - b) cout << '?' << endl;
            else cout << '+' << endl;
        }
        else if (a < b)
        {
            if (c >= b - a) cout << '?' << endl;
            else cout << '-' << endl;
        }
        else
        {
            if (c == 0) cout << 0 << endl;
            else cout << '?' << endl;
        }
    }
    return 0;
}