// MERGE_SORT_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


void MERGE(int a[], int p, int q, int r)       //p,q,r皆为数组元素序号
{
	int temp1 = q - p + 1;
	int temp2 = r - q;
	//将拆分的两部分数组分别存入新的数组
	int *bArray;
	int *cArray;
	bArray = new int[temp1];                  //因为需要动态分配内存，所以使用new建立数组
	cArray = new int[temp2];
	for (int x = 0; x < temp1; ++x)
	{
		bArray[x] = a[p + x];
	}
	for (int x = 0; x < temp2; ++x)
	{
		cArray[x] = a[q + x + 1];
	}
	int x = 0, y = 0;
	int k = p;
	for (; (k < r+1)&&(x!=temp1)&&(y!=temp2); ++k)   //如果有一个数组到达尾部则跳出循环  
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
	if (x == temp1)
	{
		for (; y<temp2; ++k,y++)             //两个数组序号都需递增
		{
			a[k] = cArray[y];
		}
	}
	else if (y == temp2)
	{
		for (; x<temp1; ++k, x++)           //两个数组序号都需递增
		{
			a[k] = bArray[x];
		}
	}
	delete[]bArray;                         //数组使用完毕需要delete[]
	delete[]cArray;                         //数组使用完毕需要delete[]
}

void MERGE_SORT(int a[], int p, int r)
{
	if (p<r)
	{
		int q = (p + r) / 2;                   //直接强制转换到int取整
		MERGE_SORT(a, p, q);
		MERGE_SORT(a, q + 1, r);
		MERGE(a, p, q, r);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int aArray[] = {100, 1, 555, 3, 11, 99, 7, 4, 6 };
	MERGE_SORT(aArray, 0, (sizeof(aArray) / 4) - 1);     //未-1导致数组超出范围，结果出现随机数
	for (int i = 0; i<sizeof(aArray) / 4; ++i)
	{
		cout << aArray[i] << endl;
	}
	return 0;
}

