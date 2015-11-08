// MERGE_SORT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void MERGE(int a[], int p, int q, int r)       //p,q,r��Ϊ����Ԫ�����
{
	int temp1 = q - p+1;
	int temp2 = r - q;
	//����ֵ�����������ֱ�����µ�����
	int *bArray;
	int *cArray;
	bArray = new int[temp1+1];                  //��Ϊ��Ҫ��̬�����ڴ棬����ʹ��new��������
	cArray = new int[temp2+1];
	for (int x = 0; x < temp1; ++x)
	{
		bArray[x] = a[p + x ];
	}
	for (int x = 0; x < temp2; ++x)
	{
		cArray[x] = a[q + x+1];
	}
	bArray[temp1] = 100000;                   //��Ҫ�������������򵥷�ֹ������Ϊ�յ����������������
	cArray[temp2] = 100000;                   //��Ҫ�������������򵥷�ֹ������Ϊ�յ����������������
	for (int k = p,x=0,y=0; k < r+1; ++k)     //δ+1��������δ��ȫ�����ҳ����ظ�����
	{
		if (bArray[x] <= cArray[y])
		{
			a[k] = bArray[x];
			x++;
		}
		else
		{
			a[k] = cArray[y];
			y++;
		}
	}
	delete []bArray;                         //����ʹ�������Ҫdelete[]
	delete []cArray;                         //����ʹ�������Ҫdelete[]
}

void MERGE_SORT(int a[],int p,int r)
{
	if (p<r)
	{
		int q = (p + r) / 2;                   //ֱ��ǿ��ת����intȡ��
		MERGE_SORT(a, p, q);
		MERGE_SORT(a, q + 1, r);
		MERGE(a,p,q,r);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int aArray[] = {2,1,555,3,11,99,7,4,6};
	MERGE_SORT(aArray, 0, (sizeof(aArray) / 4)-1);     //δ-1�������鳬����Χ��������������
	for (int i = 0; i<sizeof(aArray)/4;++i)
	{
		cout << aArray[i] << endl;
	}
	return 0;
}

