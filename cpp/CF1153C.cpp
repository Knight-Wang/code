#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        if (n & 1) { cout << ":(" << endl; continue; }
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') l++;
        }
        if (l > n / 2) { cout << ":(" << endl; continue; }
        for (int i = 0; i < n; i++)
        {
            if (l == n / 2) break;
            else if (s[i] == '?') { s[i] = '('; l++; }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '(') s[i] = ')';
        }
        l = 0; bool flg = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') l++;
            else
            {
                l--;
                if (l < 0 || (l == 0 && i != n - 1)) { flg = false; break; }
            }
        }
        if (l) flg = false;
        cout << (flg ? s : ":(") << endl;
    }
    return 0;
}