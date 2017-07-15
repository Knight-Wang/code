#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if ((a || b) && abs(a - b) <= 1) puts("YES");
    else puts("NO");
    return 0;
}