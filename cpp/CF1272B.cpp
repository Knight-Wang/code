#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int n = s.length();
        map<char, int> mp;
        mp['L'] = 0;
        mp['R'] = 0;
        mp['U'] = 0;
        mp['D'] = 0;
        for (int i = 0; i < n; i++) mp[s[i]]++;
        int x = min(mp['L'], mp['R']), y = min(mp['U'], mp['D']);
        if (x == 0) y = min(y, 1);
        else if (y == 0) x = min(x, 1);
        mp['L'] = mp['R'] = x;
        mp['U'] = mp['D'] = y;
        cout << 2 * (x + y) << endl;
        for (int i = 0; i < mp['U']; i++) cout << "U";
        for (int i = 0; i < mp['R']; i++) cout << "R";
        for (int i = 0; i < mp['D']; i++) cout << "D";
        for (int i = 0; i < mp['L']; i++) cout << "L";
        cout << endl;
    }
    return 0;
}