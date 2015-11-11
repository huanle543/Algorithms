// MAX_HEAOIFY.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void MAX_HEAPIFY(int a[], int i,int len)
{
	int l = 2 * i+1, r = 2 * i + 2;
	int largest = i;                                             //预设该节点为最大
	if (l<=len &&a[l]>a[i])
	{
		largest = l;
	}
	if (r<=len &&a[r]>a[largest])
	{
		largest = r;
	}
	if (largest!=i)
	{
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		MAX_HEAPIFY(a, largest,len);
	}
}

void BUILD_MAX_HEAO(int a[],int len)
{
	for (int i = len / 2; i > -1; --i)
	{
		MAX_HEAPIFY(a, i, len);                                        //从下往上，保证每个都是最大堆
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	int len = sizeof(a) / 4 - 1;
	BUILD_MAX_HEAO(a, len);
	for (int i = 0; i < len + 1;++i)
	{
		cout << a[i] << endl;
	}
	return 0;
}

