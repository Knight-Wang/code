#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n; string s, t;
    while (cin >> n >> s >> t)
    {
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[i]) continue;
            else if (s[i] == 'a' && t[i] == 'b') a.push_back(i + 1);
            else b.push_back(i + 1);
        }
        if ((a.size() + b.size()) & 1) { cout << -1 << endl; continue; }
        cout << (a.size() + b.size()) / 2 + a.size() % 2 << endl;
        for (int i = 1; i < a.size(); i += 2)
        {
            cout << a[i] << " " << a[i - 1] << endl;
        }
        for (int j = 1; j < b.size(); j += 2)
        {
            cout << b[j] << " " << b[j - 1] << endl;
        }
        if (a.size() & 1)
        {
            cout << a.back() << " " << a.back() << endl;
            cout << a.back() << " " << b.back() << endl;
        }
    }
    return 0;
}