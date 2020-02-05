#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        queue<pair<char, int>> q1, q2;
        bool flg = true;
        for (int i = 0; i < n; i++)
        {
            if (q1.empty() || s[i] >= q1.back().first) q1.push(make_pair(s[i], i));
            else if (q2.empty() || s[i] >= q2.back().first) q2.push(make_pair(s[i], i));
            else { flg = false; break; }
        }
        if (flg)
        {
            cout << "YES" << endl;
            string res = "";
            while (!q1.empty() && !q2.empty())
            {
                if (q1.front().second < q2.front().second)
                {
                    q1.pop();
                    res += '0';
                }
                else
                {
                    q2.pop();
                    res += '1';
                }
            }
            while (!q1.empty())
            {
                q1.pop();
                res += '0';
            }
            while (!q2.empty())
            {
                q2.pop();
                res += '1';
            }
            cout << res << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}