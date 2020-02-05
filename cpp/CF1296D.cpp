#include <bits/stdc++.h>
using namespace std;
int my_ceil(int a, int b)
{
    return (a + b - 1) / b;
}
int main()
{
    int n, a, b, k, x;
    while (cin >> n >> a >> b >> k)
    {
        int res = 0; vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            int r = x % (a + b);
            if (r == 0)
            {
                v.push_back(my_ceil(b, a));
            }
            else if (r > a)
            {
                v.push_back(my_ceil(r, a) - 1);
            }
            else
            {
                res++;
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < (int)v.size(); i++)
        {
            if (k - v[i] < 0) break;
            k -= v[i];
            res++;
        }
        cout << res << endl;
    }
    return 0;
}