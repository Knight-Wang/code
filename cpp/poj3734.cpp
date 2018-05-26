#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;
typedef vector<vector<int> > matrix;

const int MOD = 10007;

matrix multiply(matrix & a, matrix & b)
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

matrix pow(matrix & a, long long n)
{
	matrix res(a.size(), vector<int>(a[0].size()));
	for (int i = 0; i < a.size(); i++)
	{
		res[i][i] = 1;
	}
	while (n > 0)
	{
		if (n & 1)
		    res = multiply(res, a);
		a = multiply(a, a);
		n >>= 1;
	}
	return res;
}
int main()
{
	int t;
	long long n;
	cin >> t;
	while (t--)
	{
		scanf("%lld", &n);
		matrix a(3, vector<int>(3));
		a[0][0] = 2; a[0][1] = 1; 
		a[1][0] = 2; a[1][1] = 2; a[1][2] = 2;
		             a[2][1] = 1; a[2][2] = 2;
		a = pow(a, n);
	    matrix b(3, vector<int>(1));
	    b[0][0] = 1;
	    b[1][0] = 0;
	    b[2][0] = 0;
		a = multiply(a, b);
		cout << a[0][0] << endl;
	}
    return 0;	
} 