#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x; cin >> n;
        vector<int> v1, v2;
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> x;
            if (x & 1) v1.push_back(i);
            else v2.push_back(i);
        }
        int a = v1.size(), b = v2.size();
        if (a & 1)
        {
            v1.pop_back(); v2.pop_back();
        }
        else
        {
            if (a) { v1.pop_back(); v1.pop_back(); }
            else { v2.pop_back(); v2.pop_back(); }
        }
        a = v1.size(); b = v2.size();
        for (int i = 0; i < a; i += 2)
        {
            cout << v1[i] << " " << v1[i + 1] << endl;
        }
        for (int i = 0; i < b; i += 2)
        {
            cout << v2[i] << " " << v2[i + 1] << endl;
        }
    }
    return 0;
}