// 熄灯问题.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int puzzle[6][8], press[6][8];

bool guess()
{
	for (int r = 1; r < 5; r++)
	{
		for (int c = 1; c < 7; c++)
		{
			press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
		}
	}
	for (int c = 1; c < 7; c++) //判断最后一行是否熄灭
	{
		if ((press[5][c - 1] + press[5][c] + press[5][c + 1] + press[4][c]) % 2 != puzzle[5][c])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	for (int r = 1; r < 6; r++)
	{
		for (int c = 1; c < 7; c++)
		{
			scanf("%d", &puzzle[r][c]);
		}
	}
	for (int i = 0; i < 64; i++)
	{
		int w = 1;
		for (int j = 1; j < 7; j++)
		{
			press[1][7 - j] = (i & w) >> (j - 1);
			w = w << 1;
		}
		if (guess())
		{
			break;
		}
	}
	for (int r = 1; r < 6; r++)
	{
		for (int c = 1; c < 7; c++)
		{
			printf("%d ", press[r][c]);
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}
