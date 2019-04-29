#include <bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
    int n; string s;
    while (cin >> n)
    {
        cin >> s;
        for (int i = 1; i <= 9; i++) cin >> a[i];
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            if (a[s[i] - '0'] > s[i] - '0')
            {
                s[i] = char(a[s[i] - '0'] + '0');
                int j = i + 1;
                while (j < l && a[s[j] - '0'] >= s[j] - '0')
                {
                    s[j] = char(a[s[j] - '0'] + '0');
                    j++;
                }
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}