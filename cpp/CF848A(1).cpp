#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin >> k;
	for (char c = 'a'; c <= 'z'; c++)
	{
		int i = 1;
		while (i * (i - 1) / 2 <= k) i++;
		k -= (i - 1) * (i - 2) / 2;
		for (int j = 1; j < i; j++) cout << c;
	}
	return 0;
}