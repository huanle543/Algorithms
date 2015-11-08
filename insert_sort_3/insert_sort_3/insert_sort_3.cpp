// insert_sort_3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void insert_sort(int a[], int len)
{
	int temp, i;
	for (int j = len-1 ; j > -1; --j)
	{
		temp = a[j];
		i = j + 1;
		while (i<len+1 && a[i] > temp)                 //�ӵ����ڶ���Ԫ�ؿ�ʼ�Ƚϣ��������������
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
