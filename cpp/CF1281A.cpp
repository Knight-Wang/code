#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = s.length();
        if (s.substr(n - 2, 2) == "po") cout << "FILIPINO" << endl;
        else if (s.substr(n - 4, 4) == "desu" or s.substr(n - 4, 4) == "masu") cout << "JAPANESE" << endl;
        else cout << "KOREAN" << endl;
    }
    return 0;
}