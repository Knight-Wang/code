#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll mod = 1e9 + 7, p_mod = mod - 1;

matrix mat_mul(matrix & a, matrix & b)
{
    matrix c(a.size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int k = 0; k < a[0].size(); k++)
        {
            for (int j = 0; j < b[0].size(); j++)
            {
                c[i][j] = ((c[i][j] + a[i][k] * b[k][j] % p_mod) + p_mod) % p_mod;
            }
        }
    }
    return c;
}

matrix mat_pow(matrix & a, ll n)
{
    matrix res(a.size(), vector<ll>(a[0].size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while (n > 0)
    {
        if (n & 1) res = mat_mul(res, a);
        a = mat_mul(a, a);
        n >>= 1;
    }
    return res;
}

ll pow(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n, f1, f2, f3, c;
    while (cin >> n >> f1 >> f2 >> f3 >> c)
    {
        matrix x(5, vector<ll>(5, 0)), a(5, vector<ll>(1, 0));
        x[0][0] = 2; x[0][3] = -1; x[0][4] = 2;
        x[1][0] = x[2][1] = x[3][2] = x[4][4] = 1;
        a[0][0] = 2; a[4][0] = 1;
        matrix c_p = mat_pow(x, n - 4);
        c_p = mat_mul(c_p, a);
        matrix y(3, vector<ll>(3, 0)), b1(3, vector<ll>(1, 0)), b2(3, vector<ll>(1, 0)), b3(3, vector<ll>(1, 0));
        y[0][0] = y[0][1] = y[0][2] = y[1][0] = y[2][1] = 1;
        b1[2][0] = b2[1][0] = b3[0][0] = 1;
        matrix t = mat_pow(y, n - 3);
        matrix f1_p = mat_mul(t, b1);
        matrix f2_p = mat_mul(t, b2);
        matrix f3_p = mat_mul(t, b3);
        ll ans = 1;
        ans = ans * pow(c, c_p[0][0]) % mod;
        ans = ans * pow(f1, f1_p[0][0]) % mod;
        ans = ans * pow(f2, f2_p[0][0]) % mod; 
        ans = ans * pow(f3, f3_p[0][0]) % mod;
        cout << ans << endl;
    }
    return 0;
}