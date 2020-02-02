#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> v;
        string s;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s; v.push_back(s.length());
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == '0') a++;
                else b++;
            }
        }
        int cnt = a / 2 + b / 2;
        int r = a % 2 + b % 2;
        sort(v.begin(), v.end());
        int i = 0;
        for ( ; i < n; i++)
        {
            int t = v[i] / 2;
            int p = v[i] & 1;
            if (cnt < t) break;
            else if (r < p)
            {
                if (cnt == t) break;
                cnt -= t + 1; r = 1;
            }
            else { cnt -= t; r -= p; }
        }
        cout << i << endl;
    }
    return 0;
}