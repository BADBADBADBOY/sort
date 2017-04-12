// ConsoleApplication5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	printf("fxw");
//	system("pause");
//}



#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void insert_sort(int *p, int length);
void bubble_sort(int *p, int length);
void improve_bubble_sort_1(int *p, int length);
void inprove_bubble_sort_2(int *p, int length);
void  selection_sort(int *p, int length);
int main()
{
	int i;
	int array[9] = { 6,5,2,3,1,4 ,8,7,9};
	int n;
	double time;
	n = sizeof(array) / sizeof(int);
	cout << "排序前：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << array[i] << " ";

	}
	cout << endl;
	//insert_sort(array, n);
	//bubble_sort(array, n);
	//improve_bubble_sort_1(array, n);
	//inprove_bubble_sort_2(array, n);
	selection_sort(array, n);
	cout << "排序后：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << array[i] << " ";
		
	}
	cout << endl;
	system("pause");
	
}
//插入排序
void insert_sort(int *p, int length)
{
	int i;
	int j;
	int key;
	for (i = 1; i < length; i++)
	{
		j = i - 1;
		key = p[i];
		while (j>=0 && p[j] > key)
		{
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = key;
	}
	
}
//冒泡排序
void bubble_sort(int *p, int length)
{
	int i;
	int j;
	int temp;
	for (i = 0; i < length-1; i++)
	{
		for (j = 0; j < length - i-1 ; j++)
		{
			if (p[j]>p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;

			}
		}
	}
}
//改进冒泡
void improve_bubble_sort_1(int *p, int length)
{
	bool flag ;
	int i, j,temp;
	for (i = 0; i < length - 1; i++)
	{
		flag = true;
		for (j = 0; j < length - i - 1; j++)
		{
			if (p[j]>p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				flag = false;
			}
		}
		if (flag == true){
			break;
		}
	}
}
//冒泡再改进
void inprove_bubble_sort_2(int *p, int length)
{
	int i, j, temp;
	int last_swap = 0;
	int last_swap_temp = 0;
	for (i = 0; i < length ; i++)
	{
		last_swap = last_swap_temp;
		for (j =length-1 ; j > last_swap;j--)
		{
			if (p[j-1]>p[j ])
			{
				temp = p[j];
				p[j] = p[j-1 ];
				p[j -1] = temp;
				last_swap_temp = j;
			}
		}
		if (last_swap == last_swap_temp)
		{
			break;
		}
	}
}
void  selection_sort(int *p, int length)
{
	int i, j, temp;
	int min;
	for (i = 0; i < length-1; i++)
	{
		min = i;
		for (j = i + 1; j < length; j++)
		{
			if (p[min]>p[j])
			{
				min = j;
			}
		}
		temp = p[i];
		p[i] = p[min];
		p[min] = temp;
	}
}