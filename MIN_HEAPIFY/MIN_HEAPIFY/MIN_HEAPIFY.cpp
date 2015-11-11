// MIN_HEAPIFY.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void MIN_HEAPIFY(int a[], int i,int len)
{
	int l = 2 * i + 1, r = 2 * i + 2;
	int smallest = i;                                             //Ԥ��ýڵ�Ϊ���
	if (l <= len &&a[l] < a[i])
	{
		smallest = l;
	}
	if (r <= len &&a[r] < a[smallest])
	{
		smallest = r;
	}
	if (smallest != i)
	{
		int temp = a[i];
		a[i] = a[smallest];
		a[smallest] = temp;
		MIN_HEAPIFY(a, smallest, len);
	}
}

void BUILD_MIN_HEAP(int a[], int len)
{
	for (int i = len / 2; i > -1; --i)
	{
		MIN_HEAPIFY(a, i, len);                                //�������ϣ�ȷ��ÿ��������С��
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	int len = sizeof(a) / 4 - 1;
	BUILD_MIN_HEAP(a, len);
	for (int i = 0; i < len + 1; ++i)
	{
		cout << a[i] << endl;
	}
	return 0;
}

