#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0') x++;
            else y++;
        }
        if (x != y) { cout << 1 << endl << s << endl; continue; }
        cout << 2 << endl;
        cout << s[0] << " " << s.substr(1, n - 1) << endl;
    }
    return 0;
}