#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    while (cin >> n >> s)
    {
        int x = 0, minn = 101;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-') x--;
            else x++;
            if (x < 0) minn = min(minn, x);
        }
        if (minn < 0) cout << abs(minn) + x << endl;
        else cout << x << endl;
    }
    return 0;
}