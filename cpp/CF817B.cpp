#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

typedef long long ll;

int a[MAXN], last[3], num[3], n;

ll cnm(int n, int m)  
{  
    ll s = 1;  
    int k = 1;  
    if(m > n / 2)  
        m = n - m;  
    for(int i = n - m + 1; i <= n; i++)  
    {  
        s *= (ll)i;  
        while(k <= m && s % k == 0)  
        {  
            s /= (ll)k;  
            k++;  
        }  
    }  
    return s;  
}  

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int cnt = 0;
	last[0] = 0;
	int i = 1;
	while (i < n)
	{
		if (a[i] != a[last[cnt]])
		{
			num[cnt] = i - last[cnt];
			last[++cnt] = i;
		}
		if (cnt == 2) break;
		i++;
	}
	while (a[i] == a[last[cnt]] && i < n) i++;	
		num[cnt] = i - last[cnt];
	if (num[0] >= 3) cout << cnm(num[0], 3) << endl;
	else if (num[0] == 2) cout << num[1] << endl;
	else if (cnt == 1 || num[1] >= 2) cout << cnm(num[1], 2) << endl;
	else cout << num[2] << endl;
	return 0;
}