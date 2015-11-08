// Inversion_Count.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void MERGE(int a[], int p, int q, int r,int &count)       //p,q,r��Ϊ����Ԫ�����
{
	//static 
	int temp1 = q - p + 1;
	int temp2 = r - q;
	//����ֵ�����������ֱ�����µ�����
	int *bArray;
	int *cArray;
	bArray = new int[temp1];                  //��Ϊ��Ҫ��̬�����ڴ棬����ʹ��new��������
	cArray = new int[temp2];
	for (int x = 0; x < temp1; ++x)
	{
		bArray[x] = a[p + x];
	}
	for (int x = 0; x < temp2; ++x)
	{
		cArray[x] = a[q + x + 1];
	}
	int z = 0, y = 0;
	int k = p;
	for (; (k < r + 1) && (z != temp1) && (y != temp2); ++k)   //�����һ�����鵽��β��������ѭ��  
	{
		if (bArray[z] <= cArray[y])
		{
			a[k] = bArray[z];
			z++;
		}
		else
		{
			a[k] = cArray[y];
			y++;
			count = count + temp1 -z;                           //���ǰһ��������ֵ���ں�һ��������ֵ�����������ǰһ����ʣ�¸���
		}
	}
	if (z == temp1)
	{
		for (; y < temp2; ++k, y++)             //����������Ŷ������
		{
			a[k] = cArray[y];
		}
	}
	else if (y == temp2)
	{
		for (; z < temp1; ++k, z++)           //����������Ŷ������
		{
			a[k] = bArray[z];
		}
	}
	delete[]bArray;                         //����ʹ�������Ҫdelete[]
	delete[]cArray;                         //����ʹ�������Ҫdelete[]
}

void MERGE_SORT(int a[], int p, int r,int &count)
{
	if (p < r)
	{
		int q = (p + r) / 2;                   //ֱ��ǿ��ת����intȡ��
		MERGE_SORT(a, p, q,count);
		MERGE_SORT(a, q + 1, r,count);
		MERGE(a, p, q, r,count);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int aArray[] = {3,1,5,3,5,7};
	int count = 0;
	MERGE_SORT(aArray, 0, (sizeof(aArray) / 4) - 1,count);     //δ-1�������鳬����Χ��������������
	cout << count << endl;
	for (int i = 0; i < sizeof(aArray) / 4; ++i)
	{
		cout << aArray[i] << endl;
	}
	return 0;
}

