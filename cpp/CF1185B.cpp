#include <bits/stdc++.h>
using namespace std;
bool check(string a, string b)
{
    int n = a.length(), m = b.length();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j]) { i++; j++; }
        else
        {
            if (j == 0 || b[j] != a[i - 1]) return false;
            while (j < m && b[j] == a[i - 1]) j++;
        }
    }
    while (j < m && b[j] == a[i - 1]) j++;
    if (i != n || j != m) return false;
    return true;
}
int main()
{
    int n; string a, b;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            if (check(a, b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}