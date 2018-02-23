#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		cout << s;
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
} 