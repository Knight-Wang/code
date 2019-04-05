#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
struct node
{
    int t, x, y;  
};
node c[200005];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(b, 0, sizeof b);
        for (int i = 0; i < n; i++) { cin >> a[i]; b[a[i]]++; }
        int maxn = 0, maxx = 0;
        for (int i = 0; i <= 200000; i++)
        {
            if (b[i] > maxn) { maxn = b[i]; maxx = i; }
        }
        int id = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == maxx) { id = i; break; }
        }
        int cnt = 0;
        for (int i = id - 1; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
            {
                a[i] = a[i + 1];
                c[cnt].t = 2; c[cnt].x = i + 1; c[cnt].y = i + 2;
                cnt++;
            }
            else if (a[i] < a[i + 1])
            {
                a[i] = a[i + 1];
                c[cnt].t = 1; c[cnt].x = i + 1; c[cnt].y = i + 2;
                cnt++;
            }
        }
        for (int i = id + 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
            {
                a[i] = a[i - 1];
                c[cnt].t = 2; c[cnt].x = i + 1; c[cnt].y = i;
                cnt++;
            }
            else if (a[i] < a[i - 1])
            {
                a[i] = a[i - 1];
                c[cnt].t = 1; c[cnt].x = i + 1; c[cnt].y = i;
                cnt++;
            }   
        }
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++) cout << c[i].t << " " << c[i].x << " " << c[i].y << endl;
    }
    return 0;
}