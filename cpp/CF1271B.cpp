#include <bits/stdc++.h>
using namespace std;
void rev(string& s, int p)
{
    if (s[p] == 'W') s[p] = 'B';
    else s[p] = 'W';
}
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        vector<int> res;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'B') continue;
            res.push_back(i);
            s[i] = 'B';
            rev(s, i + 1);
        }
        if (s[n - 1] == 'W')
        {
            if (n % 2 == 1)
            {
                for (int i = 0; i <= n - 3; i += 2) res.push_back(i);
            }
            else { cout << -1 << endl; continue; }
        }
        cout << res.size() << endl;
        for (auto it: res) cout << it + 1 << " ";
        cout << endl;
    }
    return 0;
}