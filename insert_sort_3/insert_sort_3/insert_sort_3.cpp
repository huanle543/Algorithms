// insert_sort_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void insert_sort(int a[], int len)
{
	int temp, i;
	for (int j = len-1 ; j > -1; --j)
	{
		temp = a[j];
		i = j + 1;
		while (i<len+1 && a[i] > temp)                 //从倒数第二个元素开始比较，若满足则向后移
		{
			a[i - 1] = a[i];
			i++;
		}
		a[i - 1] = temp;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 111, 4, 2, 6, 12, 45, 5, 99 };
	insert_sort(a, (sizeof(a) / 4) - 1);
	for (int k = 0; k < sizeof(a) / 4; k++)
	{
		cout << a[k] << endl;
	}
	return 0;
}

