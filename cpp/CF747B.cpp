// CF_round387_B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int n; 
	string s;
	cin >> n >> s;
	if (n & 3)
	{
		cout << "===" << endl;
		return 0;
	}
	int tmp = n / 4;
	int cnt = 0, cntA = 0, cntG = 0, cntC = 0, cntT = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A')
			cntA++;
		if (s[i] == 'G')
			cntG++;
		if (s[i] == 'C')
			cntC++;
		if (s[i] == 'T')
			cntT++;
		if (s[i] == '?')
			cnt++;
	}
	if (cntA > tmp || cntG > tmp || cntC > tmp || cntT > tmp)
	{
		cout << "===" << endl;
		//system("pause");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] != '?')
			cout << s[i];
		else
		{
			if (cntA != tmp)
			{
				cout << 'A'; 
				cntA++;
			}
			else if (cntG != tmp)
			{
				cout << 'G';
				cntG++;
			}
			else if (cntC != tmp)
			{
				cout << 'C';
				cntC++;
			}
			else
			{
				cout << 'T';
				cntT++;
			}
		}
	}
	puts("");
	//system("pause");
	return 0;
}

