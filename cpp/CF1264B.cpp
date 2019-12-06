#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int a, b, c, d;    
    while (cin >> a >> b >> c >> d)
    {
        if (a > b)
        {
            if (a - b > 1) { cout << "NO" << endl; continue; }
            else if (c || d) { cout << "NO" << endl; continue; }
            else
            {
                cout << "YES\n";
                for (int i = 0; i < b; i++) cout << "0 1 ";
                cout << "0\n";
                continue;
            }
        }
        else if (d > c)
        {
            if (d - c > 1) { cout << "NO" << endl; continue; }
            else if (a || b) { cout << "NO" << endl; continue; }
            else
            {
                cout << "YES\n";
                for (int i = 0; i < c; i++) cout << "3 2 ";
                cout << "3\n";
                continue;
            }
        }
        else
        {
            deque<int> res1, res2, res3;
            for (int i = 0; i < a; i++) { res1.push_back(0); res1.push_back(1); }
            b -= a;
            for (int i = 0; i < d; i++) { res2.push_front(3); res2.push_front(2); }
            c -= d;
            if (abs(b - c) > 1) { cout << "NO" << endl; continue; }
            for (int i = 0; i < min(b, c); i++) { res3.push_back(2); res3.push_back(1); }
            if (b > c) res1.push_front(1);
            else if (c > b) res2.push_back(2);
            cout << "YES" << endl;
            for (auto it: res1) cout << it << " ";
            for (auto it: res3) cout << it << " ";
            for (auto it: res2) cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}