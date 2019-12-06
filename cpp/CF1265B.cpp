#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    while (cin >> t)
    {
        while (t--)
        {
            cin >> n;
            vector<int> nums(n), p(n + 1, 0);
            for (int i = 0; i < n; i++) { cin >> nums[i]; p[nums[i]] = i; }
            string res = "";
            int minn = n + 1, maxn = 0;
            for (int i = 1; i <= n; i++)
            {
                minn = min(minn, p[i]);
                maxn = max(maxn, p[i]);
                if (maxn - minn + 1 == i) res += '1';
                else res += '0';
            }
            cout << res << endl;
        }
    }
    return 0;
}