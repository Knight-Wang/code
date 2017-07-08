#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n & 1) cout << (n >> 1) << endl;
	else cout << (n >> 1) - 1 << endl;
	return 0;
}