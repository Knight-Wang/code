#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 105;
int a[N];
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        vector<pii> v;
        for (int i = 0; i < n; i++) cin >> a[i];
        int x = max_element(a, a + n) - a, y = min_element(a, a + n) - a;
        int res = a[x] - a[y];
        for (int i = 0; i < k; i++)
        {
            if (res <= 1) break;
            v.push_back(make_pair(x + 1, y + 1));
            a[x]--; a[y]++;
            x = max_element(a, a + n) - a;
            y = min_element(a, a + n) - a;
            res = a[x] - a[y];
        }
        cout << res << " " << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
            cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}