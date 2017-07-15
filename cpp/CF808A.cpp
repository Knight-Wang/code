#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int y = x;
    int t = 1, cnt = 0;
    while (x / 10)
    {
		cnt++;
        t *= 10;
        x /= 10;
    }
    t *= x + 1;
	cout << t - y << endl;
    return 0;
}