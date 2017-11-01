#include <cstdio>
using namespace std;

int main()
{
	int n = 0, cnt = 0, a = 0, now = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (now == a) cnt++;
		else
		{
			cnt--;
			if (cnt <= 0) { cnt = 1; now = a; }
		}
	}
	printf("%d\n", now);
	return 0;
}

