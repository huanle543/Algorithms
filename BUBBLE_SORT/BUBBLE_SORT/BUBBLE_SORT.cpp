// BUBBLE_SORT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void Bubble_Sort(int a[],int len)
{
	//int len = sizeof(a) / 4;
	for (int i = 0; i < len;++i)
	{
		for (int j = len-1; j > i;--j)
		{
			if (a[j]<a[j-1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 9, 7, 5, 9, 6, 4, 87, 3, 7, 1 };
	Bubble_Sort(a, sizeof(a) / 4);
	for (auto c:a)
	{
		cout << c << endl; 
	}
	return 0;
}

