#include <bits/stdc++.h>
using namespace std;
double cal(int x)
{
    if (x >= 95 && x <= 100) return 4.3;
    else if (x >= 90 && x <= 94) return 4.0;
    else if (x >= 85 && x <= 89) return 3.7;
    else if (x >= 80 && x <= 84) return 3.3;
    else if (x >= 75 && x <= 79) return 3.0;
    else if (x >= 70 && x <= 74) return 2.7;
    else if (x >= 67 && x <= 69) return 2.3;
    else if (x >= 65 && x <= 66) return 2.0;
    else if (x >= 62 && x <= 64) return 1.7;
    else if (x >= 60 && x <= 61) return 1.0;
    else return 0;
}
int main()
{
    map<int, double> mp;
    for (int n = 0; n <= 200; n++)
    {
        double res = 0;
        for (int i = 0; i <= 100; i++)
        {
            int j = n - i;
            if (j < 0 || j > 100) continue;
            res = max(res, cal(i) + cal(j));
            
        }
        mp[n] = res;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        double res = 0;
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                int k = n - i - j;
                if (k < 0 || k > 200) continue;
                res = max(res, cal(i) + cal(j) + mp[k]);
            }
        }
        printf("%.1lf\n", res);
    }
    return 0;
}