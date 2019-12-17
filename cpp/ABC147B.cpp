#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int n = s.length();
        int l = 0, r = n - 1, res = 0;
        while (l < r)
        {
            if (s[l] != s[r]) res++;
            l++; r--;
        }
        cout << res << endl;
    }
    return 0;
}