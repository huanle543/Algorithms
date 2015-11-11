// QUICK_SORT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int PARTITION(int a[], int p, int r)                                           //以递增顺序排序
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r;++j)
	{
		if (a[j]<x)
		{
			++i;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}

void QUICK_SORT(int a[], int p, int r)
{
	if (p<r)
	{
		int q = PARTITION(a, p, r);
		QUICK_SORT(a, p, q - 1);
		QUICK_SORT(a, q + 1, r);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 3, 1, 7, 5, 9, 4, 12, 0 };
	int len = sizeof(a) / 4 - 1;
	QUICK_SORT(a, 0,len);
	for (int i = 0; i < len + 1;++i)
	{
		cout << a[i] << endl;
	}
	return 0;
}

