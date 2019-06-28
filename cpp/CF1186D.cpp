#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
double a[N];
ll b[N];
int main()
{
    int n;
    while (cin >> n)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i]; b[i] = floor(a[i]); sum += b[i];
        }
        if (sum < 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (ceil(a[i]) - b[i] == 1)
                {
                    sum++; b[i]++;
                }
                if (sum == 0) break;
            }
        }
        for (int i = 1; i <= n; i++) cout << b[i] << endl;
    }
    return 0;
}