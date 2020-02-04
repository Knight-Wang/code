#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int i = n;
        while (i >= 1 && a[i] >= n - i) i--;
        i++;
        int j = 1;
        while (j <= n && a[j] >= j - 1) j++;
        j--;
        if (j >= i) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}