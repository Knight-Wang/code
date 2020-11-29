#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> res;
        for (int i = 0; i < n; i++) res.push_back(n - i);
        if (n & 1) swap(res[n + 1 >> 1], res[n >> 1]);
        for (int i = 0; i < n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}