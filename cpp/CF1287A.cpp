#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while (cin >> t)
    {
        while (t--)
        {
            int k; string s; cin >> k >> s;
            int maxn = 0;
            for (int i = 0; i < k; i++)
            {
                if (s[i] == 'A')
                {
                    int j = i + 1;
                    while (j < k && s[j] == 'P') j++;
                    maxn = max(maxn, j - i - 1);
                    i = j - 1;
                }
            }
            cout << maxn << endl;
        }
    }
    return 0;
}