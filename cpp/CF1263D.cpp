#include <bits/stdc++.h>
using namespace std;
const int N = 200030;
int p[N];
void init(int n)
{
    for (int i = 0; i < n + 26; i++) p[i] = i;
}
int find(int x)
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
void uni(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) p[x] = y;
}
int main()
{
    int n;
    while (cin >> n)
    {
        init(n);
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            for (auto it: v[i])
            {
                uni(i, n + it - 'a');
            }
        }
        set<int> st;
        for (int i = 0; i < n; i++) st.insert(find(i));
        cout << st.size() << endl;
    }
    return 0;
}