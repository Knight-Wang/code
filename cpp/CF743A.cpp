#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int a, b, n;
	string s;
	cin >> n >> a >> b >> s;
	cout << (s[a - 1] != s[b - 1]) << endl;
	//system("pause");
	return 0;
}

