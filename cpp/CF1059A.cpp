#include <iostream>
using namespace std;
int t[100005], l[100005];
int main()
{
	int n, L, a;
	while (cin >> n >> L >> a)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> t[i] >> l[i];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp = t[i] - (t[i - 1] + l[i - 1]);
			cnt += tmp / a;
		}
		cnt += (L - (t[n] + l[n])) / a;
		cout << cnt << endl;
	}
	return 0;
}

