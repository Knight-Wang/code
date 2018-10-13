#include <iostream>
using namespace std;
int main()
{
	int t, v, L, l, r;
	cin >> t;
	while (t--)
	{
		cin >> L >> v >> l >> r;
		cout << L / v - (r / v - (l + v - 1) / v + 1) << endl;
	}	
	return 0;
}
