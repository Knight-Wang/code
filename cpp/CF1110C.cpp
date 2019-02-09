#include <bits/stdc++.h>
using namespace std;

inline int max_fac(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return x / i;
    }
    return 1;
}

int main()
{
    int q, x;
    set<int> st;
    for (int i = 1; i <= 25; i++) st.insert((1 << i) - 1);
    while (cin >> q)
    {
        for (int i = 0; i < q; i++)
        {
            cin >> x;
            if (st.count(x))
            {
                cout << max_fac(x) << endl;   
            }
            else
            {
                int tmp = 0, y = x;
                while (y) { y >>= 1; tmp++; }
                cout << (1 << tmp) - 1 << endl; 
            }
        }
    }
    return 0;
}