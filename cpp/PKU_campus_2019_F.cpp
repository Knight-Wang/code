#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[6], b[6];
struct d
{
    int x, a, b;    
};
struct course
{
    int id, t, s;
    vector<d> v;    
};
course c[11];
inline bool overlap(d & p, d & q)
{
    if (p.x != q.x) return false;
    else if (q.a > p.b || q.b < p.a) return false;
    return true;
}
bool conf(int a, int b)
{
    for (int i = 0; i < c[a].v.size(); i++)
    {
        for (int j = 0; j < c[b].v.size(); j++)
        {
            if (overlap(c[a].v[i], c[b].v[j])) return true;
        }
    }
    return false;
}
bool check(int x, int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int tmp = 1 << i;
        if (tmp & x) v.push_back(i);
    }
    int tmp[6];
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < v.size(); i++) tmp[c[v[i]].t]++;
    if (tmp[3] > 1 || tmp[4] > 1 || tmp[5] > 1) return false;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += c[v[i]].s;
    }
    if (sum > 25) return false;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (conf(v[i], v[j])) return false;
        }
    }
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < v.size(); i++)
    {
        tmp[c[v[i]].t] += c[v[i]].s;
    }
    for (int i = 1; i <= 5; i++) 
    {
        if (a[i] + tmp[i] < b[i]) return false;
    }
    return true;
}
void print(int x, int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int tmp = 1 << i;
        if (tmp & x) v.push_back(c[i].id);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}
int main()
{
    int T, n, k, x, p, q;
    cin >> T;
    while (T--)
    {
        for (int i = 1; i <= 5; i++) cin >> a[i];
        for (int i = 1; i <= 5; i++) cin >> b[i];
        cin >> n;
        for (int i = 0; i < n; i++) c[i].v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> c[i].id >> c[i].t >> c[i].s;
            cin >> k;
            while (k--)
            {
                cin >> x >> p >> q;
                c[i].v.push_back(d{x, p, q});
            }
        }
        if (a[1] >= b[1] && a[2] >= b[2] && a[3] >= b[3] && a[4] >= b[4] && a[5] >= b[5])
        {
            cout << "able to graduate" << endl;
            continue;
        }
        int ans = -1, minn = INF;
        for (int i = 0; i < (1 << n); i++)
        {
            if (check(i, n) && __builtin_popcount(i) < minn)
            {
                ans = i;
                minn = __builtin_popcount(i);
            }
        }
        if (ans != -1)
        {
            cout << "able to graduate" << endl;
            print(ans, n);
        }
        else cout << "unable to graduate" << endl;
    }
    return 0;
}