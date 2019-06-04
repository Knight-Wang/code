#include <bits/stdc++.h>
using namespace std;
int vis[1 << 18];
int main()
{
    int n, x;
    while (cin >> n >> x)
    {
        memset(vis, 0, sizeof vis);
        vector<int> v;
        if (x >= (1 << n)) 
        {
            for (int i = 1; i < (1 << n); i++) v.push_back(i);
        }
        else
        {
            for (int i = 1; i < (1 << n); i++)
            {
                if (i == x) continue;
                else if (!vis[i]) { v.push_back(i); vis[i ^ x] = 1; }
            }
        }
        cout << v.size() << endl;
        if (!v.empty())
        {
            cout << v[0] << " ";
            for (int i = 1; i < (int)v.size(); i++) cout << (v[i - 1] ^ v[i]) << " ";
            cout << endl;            
        }
    }
    return 0;
}