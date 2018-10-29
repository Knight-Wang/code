#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		cout << "0 ";
		int n = s.length();
		if (n == 1) { cout << endl; continue; }
		for (int i = 1; i < n - 1; i++)
		{
			if (s[i] != s[i + 1]) 
			{ 
				cout << "1 ";
				reverse(s.begin(), s.begin() + i + 1);
			}
			else cout << "0 ";
		}
		if (s[n - 1] == 'a') cout << "1 ";
		else cout << "0 ";
		cout << endl;
	}
	return 0;
}