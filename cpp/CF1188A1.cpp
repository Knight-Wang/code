#include <bits/stdc++.h>
using namespace std;
 
int in[100005];
int main()
{
    int n, x, y;
    while (cin >> n)
    {
        memset(in, 0, sizeof in);
        for (int i = 0; i < n - 1; i++) { cin >> x >> y; in[x]++; in[y]++; }
        bool flg = false;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 2) { flg = true; break; }
        }
        cout << (flg ? "NO" : "YES") << endl;
    }
    return 0;
}