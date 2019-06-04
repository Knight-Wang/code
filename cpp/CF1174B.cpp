#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] & 1) odd = 1;
            else even = 1;
        }
        if (odd + even == 2)
        {
            sort(a + 1, a + n + 1);    
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}