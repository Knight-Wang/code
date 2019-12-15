#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int main()
{
    int n, px, py;
    while (cin >> n >> px >> py)
    {
        int x, y, u = 0, d = 0, l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if (x == px)
            {
                if (y > py) u++;
                else d++;
            }
            else if (y == py)
            {
                if (x < px) l++;
                else r++;
            }
            else
            {
                if (x < px && y > py) { u++; l++; }
                else if (x > px && y > py) { u++; r++; }
                else if (x < px && y < py) { d++; l++; }
                else { d++; r++; }
            }
        }
        vector<int> v;
        v.push_back(u); v.push_back(d); v.push_back(l); v.push_back(r);
        int p = max_element(v.begin(), v.end()) - v.begin();
        cout << v[p] << endl;
        cout << px + dx[p] << " " << py + dy[p] << endl;
    }
    return 0;
}