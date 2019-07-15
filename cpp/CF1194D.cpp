#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int q, n, k;
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        if (k % 3 == 0)
        {
            int t = n % (k + 1);
            cout << (t % 3 == 0 && t != k ? "Bob" : "Alice") << endl;
        }
        else
        {
            cout << (n % 3 == 0 ? "Bob" : "Alice") << endl;   
        }
    }
    return 0;
}