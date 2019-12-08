#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j + 1 < n && s[j + 1] == s[j]) j++;
            if (j + 1 < n && s[j + 1] != s[j]) cnt += j - i + 1;
            i = j;
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j + 1 < n && s[j + 1] == s[j]) j++;
            if (j + 1 < n && s[j + 1] != s[j]) cnt += j - i;
            i = j;
        }
        cout << (long long)n * (n - 1) / 2 - cnt << endl;
    }
    return 0;
}