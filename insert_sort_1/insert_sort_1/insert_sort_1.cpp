// insert_sort_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void insert_sort(int a[],int len)
{
	int temp,i;
	for (int j = 1; j < len ; ++j)
	{
		temp = a[j];
		i = j - 1;
		while (i>-1 && a[i] > temp)          //���αȽϺ�����������ǰ����
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

