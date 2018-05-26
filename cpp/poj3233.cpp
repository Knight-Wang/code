#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > matrix;

matrix multiply(matrix & a, matrix & b, int MOD)
{
	matrix c(a.size(), vector<int>(b[0].size()));
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < a[0].size(); k++)
		{
			for (int j = 0; j < b[0].size(); j++)
			{
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return c;
}

matrix pow(matrix & a, int n, int m)
{
	matrix res(a.size(), vector<int>(a[0].size()));
	for (int i = 0; i < a.size(); i++)
	{
		res[i][i] = 1;
	}
	while (n > 0)
	{
		if (n & 1)
		    res = multiply(res, a, m);
		a = multiply(a, a, m);
		n >>= 1;
	}
	return res;
}

int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	matrix a(n * 2, vector<int>(n, 0)), b(n * 2, vector<int>(n * 2, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i][i] = b[n + i][i] = b[n + i][n + i] = 1;
	}
	matrix b_k = pow(b, k + 1, m);
	matrix ans = multiply(b_k, a, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = ans[n + i][j];
			if (i == j) tmp = (tmp - 1 + m) % m;
			cout << tmp << " ";
		}
		cout << endl;
	}
	return 0;
}