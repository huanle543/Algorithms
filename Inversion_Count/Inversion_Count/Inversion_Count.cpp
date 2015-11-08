// Inversion_Count.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void MERGE(int a[], int p, int q, int r,int &count)       //p,q,r皆为数组元素序号
{
	//static 
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
	int z = 0, y = 0;
	int k = p;
	for (; (k < r + 1) && (z != temp1) && (y != temp2); ++k)   //如果有一个数组到达尾部则跳出循环  
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
			count = count + temp1 -z;                           //如果前一部分数组值大于后一部分数组值，则计数加上前一组数剩下个数
		}
	}
	if (z == temp1)
	{
		for (; y < temp2; ++k, y++)             //两个数组序号都需递增
		{
			a[k] = cArray[y];
		}
	}
	else if (y == temp2)
	{
		for (; z < temp1; ++k, z++)           //两个数组序号都需递增
		{
			a[k] = bArray[z];
		}
	}
	delete[]bArray;                         //数组使用完毕需要delete[]
	delete[]cArray;                         //数组使用完毕需要delete[]
}

void MERGE_SORT(int a[], int p, int r,int &count)
{
	if (p < r)
	{
		int q = (p + r) / 2;                   //直接强制转换到int取整
		MERGE_SORT(a, p, q,count);
		MERGE_SORT(a, q + 1, r,count);
		MERGE(a, p, q, r,count);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int aArray[] = {3,1,5,3,5,7};
	int count = 0;
	MERGE_SORT(aArray, 0, (sizeof(aArray) / 4) - 1,count);     //未-1导致数组超出范围，结果出现随机数
	cout << count << endl;
	for (int i = 0; i < sizeof(aArray) / 4; ++i)
	{
		cout << aArray[i] << endl;
	}
	return 0;
}

