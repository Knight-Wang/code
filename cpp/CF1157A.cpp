#include <bits/stdc++.h>
using namespace std;
int f(int x)
{
    x++;
    while (x % 10 == 0) x /= 10;
    return x;
}
int main()
{
    int n;
    while (cin >> n)
    {
        set<int> st;
        st.insert(n);
        while (!st.count(f(n))) { st.insert(f(n)); n = f(n); }
        cout << st.size() << endl;
    }
    return 0;
}