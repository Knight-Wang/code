#include <bits/stdc++.h>
using namespace std;
string s; int p = 0;
int dfs()
{
    int ans = 0, t = 0;
    while (true)
    {
        if (s[p] == '(') { p++; t += dfs(); }
        else if (s[p] == 'x') { t++; p++; }
        else if (s[p] == '|') { ans = max(ans, t); t = 0; p++; }
        else
        {
            ans = max(ans, t);
            p++;
            break;
        }
    }
    return ans;
}
int main()
{
    cin >> s;
    cout << dfs() << endl;
    return 0;
}