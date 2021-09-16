/*
斐波那契查找
Author: Henrt wang
2021-9-16
*/

#include <iostream>
#include <vector>

using namespace std;

/*斐波那契数组*/
int fib[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377 };
/*斐波那契查找函数*/
int fibonacci_search(int num,int* arr,int length);

int main()
{
	int arr[] = { 1, 2, 4, 6, 7, 9, 13,
		16, 17, 21, 23, 25, 27,
		31, 45, 56, 58, 61, 65,
		67, 73, 75, 88, 93, 102 };
	cout << fibonacci_search(93, arr, sizeof(arr) / sizeof(int));
}

int fibonacci_search(int num, int* arr, int length)
{
	int n = 0;//找到数组长度对应的斐波那契数列项数
	for (int i = 0; i < length; i++)
	{
		if (fib[i] >= length)
		{
			n = i;
			break;
		}
	}
	vector<int> v;
	for (int i = 0; i < length; i++)
		v.push_back(*(arr + i));
	if (length < fib[n])//判断是否要延长数组
	{		
		for (int i = length; i < fib[n]; i++)
			v.push_back(*(arr + length - 1));
	}
	int l = 0;//初始化左节点为0
	int mid = l + fib[n - 1] - 1;//初始化中间节点
	while (v[mid] != num)
	{
		if (v[mid] < num)
		{//如果中间节点比要找的数小，则将区间右移
			l = mid + 1;
			n = n - 2;
		}
		else
		{//如果中间节点比要找的数大，则做端点不动，移动中间节点
			n = n - 1;
		}
		mid = l + fib[n - 1] - 1;
	}
	return mid;
}