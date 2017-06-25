#include <iostream>
#include <cstdio>
using namespace std;

bool check(int hour, int min)
{
	return hour % 10 == min / 10 && hour / 10 == min % 10;
}

int main()
{
	int hour, min;
	scanf("%d:%d", &hour, &min);
	int cnt = 0;
	while (!check(hour, min))
	{
		cnt++;
		min++;
		if (min == 60)
		{
			min = 0;
			hour++;
			if (hour == 24) hour = 0;
		}
	}
	cout << cnt << endl;
	return 0;
}