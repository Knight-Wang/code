#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t; getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        int n = s.length();
        queue<int> o, e;
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - '0') & 1) o.push(s[i] - '0');
            else e.push(s[i] - '0');
        }
        while (!o.empty() && !e.empty())
        {
            if (o.front() < e.front()) { cout << o.front(); o.pop(); }
            else { cout << e.front(); e.pop(); }
        }
        while (!o.empty()) { cout << o.front(); o.pop(); }
        while (!e.empty()) { cout << e.front(); e.pop(); }
        cout << endl;
    }
    return 0;
}