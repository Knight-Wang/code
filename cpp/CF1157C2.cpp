#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n == 1) { cout << "1\nL" << endl; continue; }
        vector<char> v;
        vector<int> ans;
        ans.push_back(0);
        int l = 1, r = n;
        while (true)
        {
            if (l > r || (a[l] <= ans.back() && a[r] <= ans.back())) break;
            if (a[l] > ans.back())
            {
                if (a[r] > ans.back())
                {
                    if (a[l] < a[r])
                    {
                        ans.push_back(a[l]);
                        v.push_back('L');
                        l++;
                    }
                    else if (a[l] > a[r])
                    {
                        ans.push_back(a[r]);
                        v.push_back('R');
                        r--;
                    }
                    else
                    {
                        int k = l + 1, maxn = 0;
                        char tmp = 'L';
                        while (k < r && a[k] > a[k - 1]) k++;
                        maxn = k - l;
                        k = r - 1;
                        while (k > l && a[k] > a[k + 1]) k--;
                        if (r - k > maxn) { tmp = 'R'; maxn = r - k; }
                        for (int i = 0; i < maxn; i++) v.push_back(tmp);
                        break;
                    }
                }
                else
                {
                    ans.push_back(a[l]);
                    v.push_back('L');
                    l++;
                }
            }
            else
            {
                ans.push_back(a[r]);
                v.push_back('R');
                r--;
            }
        }
        cout << v.size() << endl;
        for (auto it: v) cout << it;
        cout << endl;
    }
    return 0;
}