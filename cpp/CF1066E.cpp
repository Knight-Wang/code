#include <iostream>
using namespace std;
const int MOD = 998244353;
char a[200005], b[200005];
int sum[200005];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = n - 1; i >= 0; i--) cin >> a[i];
		for (int i = m - 1; i >= 0; i--) 
		{ 
			cin >> b[i]; 
			sum[i] = sum[i + 1] + b[i] - '0'; 
		}
		long long ans = 0, pw = 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == '1')
				ans = (ans + (sum[i] * pw) % MOD) % MOD;
			pw = pw * 2 % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
