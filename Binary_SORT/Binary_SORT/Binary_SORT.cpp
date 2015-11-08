// Binary_SORT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int Binary_Sort(int a[], int i, int j, int value)
{
	if (i<=j)
	{
		int mid = (i + j) / 2;
		if (value <a[mid])
		{
			Binary_Sort(a, i, mid - 1, value);
		}
		else if (value > a[mid])
		{
			Binary_Sort(a, mid + 1, j, value);
		}
		else
			return mid;
	}
	else
	    return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num = 3;
	int a[] = { 1, 2, 3, 4, 5, 9};
	int result = Binary_Sort(a, 0, sizeof(a) / 4 - 1, num);
	switch (result)
	{
	case -1:
		cout << "not found" << endl;
		break;
	default:
		cout << "find : a[" << result << "]="<< a[result] << endl;
		break;
	}
	return 0;
}

