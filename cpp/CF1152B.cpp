#include <bits/stdc++.h>
using namespace std;
bool check(int x)
{
    x++;
    int cur = 1;
    for (int i = 0; i < 25; i++)
    {
        if (x == cur) return true;
        cur <<= 1;
    }
    return false;
}
int main()
{
    int x;
    while (cin >> x)
    {
        int t = 1, b = 1;
        while (t <= x) { t <<= 1; b++; }
        t >>= 1; b--;
        vector<int> v;
        int cnt = 0;
        while (!check(x))
        {
            while (t & x) { t >>= 1; b--; }
            v.push_back(b);
            x ^= (t << 1) - 1;
            cnt++;
            if (check(x)) break;
            x++;
            cnt++;
        }
        cout << cnt << endl;
        if (!v.empty())
        {
            for (auto it: v) cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}