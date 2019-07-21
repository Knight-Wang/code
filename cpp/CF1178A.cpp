#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int tot = accumulate(a + 1, a + n + 1, 0);
        int sum = a[1]; vector<int> v;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] * 2 <= a[1]) { sum += a[i]; v.push_back(i); }
        }
        if (sum * 2 > tot)
        {
            cout << v.size() + 1 << endl;
            cout << 1 << " ";
            for (auto it: v) cout << it << " ";
            cout << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}