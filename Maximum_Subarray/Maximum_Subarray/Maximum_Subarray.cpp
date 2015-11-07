// Maximum_Subarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct result
{
public:
	int left, right, sum;
};

struct result Find_Max_Crossing_Subarray(int a[],int low,int mid,int high)
{
	result cross;
	int left_sum = -1000,right_sum = -1000;
	int sum = 0;
	for (int i = mid; i > low;--i)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			cross.left = i;
		}
	}
	sum = 0;
	for (int i = mid + 1; i < high; ++i)
	{
		sum += a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			cross.right = i;
		}
	}
	cross.sum = left_sum + right_sum;
	return cross;
}

struct result Find_Maximum_Subarray(int a[], int low, int high)
{
	result max,max_left,max_right,max_cross;
	int mid = 0;
	if (low == high)
	{
		max.left = low;
		max.right = high;
		max.sum = a[high];
		return max;
	}
	else
	{
		mid = (low + high) / 2;
		max_left = Find_Maximum_Subarray(a, low, mid);
		max_right = Find_Maximum_Subarray(a, mid + 1, high);
		max_cross = Find_Max_Crossing_Subarray(a, low, mid, high);
		if (max_left.sum >= max_right.sum && max_left.sum >= max_cross.sum)
		{
			return max_left;
		}
		else if (max_right.sum >= max_left.sum && max_right.sum >= max_cross.sum)
			return max_right;
		else
			return max_cross;
	}		
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	result result_max;
	result_max = Find_Maximum_Subarray(a, 0, sizeof(a) / 4 - 1);
	cout << result_max.left << endl;
	cout << result_max.right << endl;
	cout << result_max.sum << endl;
	return 0;
}

