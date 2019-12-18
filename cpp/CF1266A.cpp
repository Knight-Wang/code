#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        vector<int> c(10, 0);
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            c[s[i] - '0']++;
        }
        int res = 0;
        for (int i = 0; i < 10; i++) res += i * c[i];
        if (res == 0) { cout << "red" << endl; continue; }
        if (res % 3 == 0 && (c[0] > 1 || (c[0] == 1 && (c[2] || c[4] || c[6] || c[8]))))
        {
            cout << "red" << endl;
        }
        else cout << "cyan" << endl;
    }
    return 0;
}