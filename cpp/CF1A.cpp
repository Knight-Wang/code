#include <iostream>
#include <cstdio>
using namespace std;

long long n, m, a;

int main()
{
	//freopen("c:\\users\\wangyiming\\desktop\\in.txt", "r", stdin);
	cin >> n >> m >> a;
	cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
	return 0;
}