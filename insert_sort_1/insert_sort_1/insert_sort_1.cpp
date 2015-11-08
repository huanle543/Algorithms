// insert_sort_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void insert_sort(int a[],int len)
{
	int temp,i;
	for (int j = 1; j < len ; ++j)
	{
		temp = a[j];
		i = j - 1;
		while (i>-1 && a[i] > temp)          //依次比较后，若满足则向前插入
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = temp;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 3,4,2,6,12,45,5,1 };
	insert_sort(a,sizeof(a)/4);
	for (int k = 0; k < sizeof(a)/4; k++)
	{
		cout << a[k] << endl;
	}
	return 0;
}

