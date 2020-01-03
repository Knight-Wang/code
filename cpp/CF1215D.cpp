#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        int a = 0, b = 0, pa = 0, pb = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == '?') pa++;
            else a += s[i] - '0';
        }
        for (int i = n / 2; i < n; i++)
        {
            if (s[i] == '?') pb++;
            else b += s[i] - '0';
        }
        if (a == b)
        {
            cout << (pa != pb ? "Monocarp" : "Bicarp") << endl;
        }
        else
        {
            if (a < b) { swap(a, b); swap(pa, pb); }
            a -= b;
            if (pa >= pb) cout << "Monocarp" << endl;
            else
            {
                pb -= pa;
                cout << (pb / 2 * 9 == a ? "Bicarp" : "Monocarp") << endl;
            }
        }
    }
    return 0;
}