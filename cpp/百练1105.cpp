#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, Case = 1;
	while (cin >> n, n)
	{
		cout << "S-Tree #" << Case++ << ":" << endl;
		vector<string> v;
		string tmp, vva;
		for (int i = 0; i < n; i++) 
		{
			cin >> tmp; v.push_back(tmp);
		}
		cin >> tmp;
		int t;
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			cin >> vva;
			int sum = 0;
			for (int j = 1; j <= n; j++)
			{
				if (j > 1) sum <<= 1;				
				sum += (vva[v[j - 1][1] - '1'] - '0');
			}
			cout << tmp[sum];
		}
		cout << endl << endl;
	}
	return 0;
}