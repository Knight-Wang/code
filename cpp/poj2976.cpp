#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
int a[MAXN], b[MAXN], n, k;
double buf[MAXN];
bool check(double m)
{
    for (int i = 0; i < n; i++) buf[i] = a[i] - m * b[i];
    sort(buf, buf + n);
    double sum = 0;
    for (int i = n - 1; i >= k; i--)
        sum += buf[i];
    return sum >= 0;
}
int main()
{
    while (scanf("%d %d", &n, &k), n || k)
    {
        for (int i = 0; i < n; i++)    scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)    scanf("%d", &b[i]);
        double l = 0, r = 100, ans = 0;
        for (int i = 0; i < 100; i++)
        {
            double m = (l + r) / 2;
            if (check(m)) { ans = m; l = m; }
            else r = m;
        }
        printf("%d\n", (int)(ans * 100 + 0.5));
    }
    return 0;
}