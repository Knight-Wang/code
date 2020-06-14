#include <bits/stdc++.h>
using namespace std;
 
bool check(int L, int R, int l, int r)
{
    if (l > R || r < L) return false;
    return true;
}
 
void uni(int &L, int &R, int l, int r)
{
    L = min(L, l);
    R = max(R, r);
}
 
int main()
{
    int t, n, x, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> m;
        int L = 0, R = 0, i = 0;
        int l = 0, r = 0;
        for ( ; i < m; i++)
        {
            cin >> l >> r;
            if (l <= x && r >= x) { L = l; R = r; break; }
        }
        for (int j = i + 1; j < m; j++)
        {
            cin >> l >> r;
            if (check(L, R, l, r)) uni(L, R, l, r);
        }
        cout << R - L + 1 << endl;
    }
    return 0;
}