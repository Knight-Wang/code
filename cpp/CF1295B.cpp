#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x; string s;
        cin >> n >> x >> s;
        vector<int> v; int c =  0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0') c++;
            v.push_back(2 * c - i - 1);
        }
        c = 2 * c - n;
        int res = 0;
        bool flg = true;
        for (int i = 0; i < n; i++)
        {
            if (x == v[i])
            {
                if (c == 0) { flg = false; break; }
                else
                {
                    res++;
                }
            }
            else if (c != 0 && (long long)c * (x - v[i]) > 0)
            {
                if (abs(x - v[i]) >= c && (x - v[i]) % c == 0)
                {
                    res++;
                }
            }
        }
        if (x == 0) res++;
        if (!flg) cout << -1 << endl;
        else cout << res << endl; 
    }
    return 0;
}