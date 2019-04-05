#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        vector<int> x, y;
        x.push_back(a[0]);
        int last = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                if (last == 0) { y.push_back(a[i]); last = 1; }
                else { x.push_back(a[i]); last = 0; }
            }
            else
            {
                if (last == 0) x.push_back(a[i]);
                else y.push_back(a[i]);
            }
        }
        bool flg = true;
        for (int i = 0; i < (int)x.size() - 1; i++)
        {
            if (x[i + 1] == x[i]) { flg = false; break; }
        }
        if (!flg) { cout << "NO" << endl; continue; }
        for (int i = 0; i < (int)y.size() - 1; i++)
        {
            if (y[i + 1] == y[i]) { flg = false; break; }
        }
        if (!flg) { cout << "NO" << endl; continue; }
        cout << "YES" << endl;
        cout << x.size() << endl;
        for (auto it: x) cout << it << " ";
        cout << endl;
        cout << y.size() << endl;
        for (int i = y.size() - 1; i >= 0; i--) cout << y[i] << " ";
        cout << endl;
    }
    return 0;
}