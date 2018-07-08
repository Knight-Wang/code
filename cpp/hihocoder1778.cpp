#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[1000005], A, B;
int n;
ll maxSum()
{
	ll maxsum = -INF, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum = max(sum + a[i], a[i]);
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

ll minSum()
{
	ll minsum = INF, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum = min(sum + a[i], a[i]);
        minsum = min(minsum, sum);
    }
    return minsum;
}

int main()
{
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (A >= 0) cout << A * maxSum() + B << endl;
	else cout << A * minSum() + B << endl;
	return 0;
}