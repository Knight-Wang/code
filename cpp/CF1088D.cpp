#include <bits/stdc++.h>
using namespace std;
void out(char x, int a, int b)
{
    cout << x << " " << a << " " << b << endl;
    fflush(stdout);
}
int main()
{
    int a, b;
    char big = 'a';
    out('?', 0, 0);
    cin >> a;
    if (a == -1) big = 'b';
    int x = 0, y = 0;
    for (int i = 29; i >= 0; i--)
    {
        int t = 1 << i;
        x |= t; y &= ~t;
        out('?', x, y);
        cin >> a;
        x ^= t; y ^= t;
        out('?', x, y);
        cin >> b;
        if (a == -1 && b == 1)
        {
            x |= t; y |= t;
        }
        else if (a == 1 && b == -1)
        {
            x &= ~t; y &= ~t;
        }
        else if (a == b)
        {
            if (big == 'a')
            {
                x |= t; y &= ~t;
                if (a == -1) big = 'b'; 
            }
            else
            {
                x &= ~t; y |= t;
                if (a == 1) big = 'a';
            }
        }
    }
    out('!', x, y);
    return 0;
}