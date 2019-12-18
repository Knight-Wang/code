#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c, s;
        cin >> c >> s;
        int a = s / c, b = s % c;
        cout << (a + 1) * (a + 1) * b + a * a * (c - b) << endl;
    }
    return 0;
}