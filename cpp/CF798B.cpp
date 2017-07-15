#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
string a[55];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int l = a[0].length(), minn = INF;
	string tmp = a[0];
	bool flg = true;
	for (int i = 0; i < l; i++)
	{
		if (!flg) break;
		if (i) tmp = tmp.substr(1, l - 1) + tmp[0];
		int sum = i;
		for (int j = 1; j < n; j++)
		{
			string t = a[j];
			int cnt = 0;
			while (cnt < l && t != tmp) 
			{
				t = t.substr(1, l - 1) + t[0];
				cnt++;
			}
			if (cnt == l)
			{
				flg = false; break;
			}
			sum += cnt;
		}
		if (sum < minn) minn = sum;
	}
	cout << (!flg ? -1 : minn) << endl;
	return 0;
}