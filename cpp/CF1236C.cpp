#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>> p(n, vector<int>());
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (j & 1) p[i].push_back(j * n + i + 1);
                else p[n - 1 - i].push_back(j * n + i + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (auto it: p[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}