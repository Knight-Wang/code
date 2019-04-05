#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        bool flg = true;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i + 1] != s[i] + 1) { flg = false; break; }
        }
        cout << (flg ? "Yes" : "No") << endl;
    }
    return 0;
}