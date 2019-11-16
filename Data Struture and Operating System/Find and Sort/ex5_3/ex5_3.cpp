// ex5_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0


int insertsort(int x[], int n)
{
	int i, j;
	int a;
	for (i = 0; i < n - 1; i++)
	{
		a = x[i + 1];
		j = i;
		while (j > -1 && a < x[j])
		{
			x[j + 1] = x[j];
			j--;
		}
		x[j + 1] = a;
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d", x[j]);
	}
	return 1;
}

int selectsort(int x[], int n)
{
	int i, j, small;
	int swap;
	for (i = 0; i < n - 1; i++)
	{
		small = i;
		for (j = i + 1; j < n; j++)
		{
			if (x[j] < x[small])
				small = j;
		}
		if (small != j)
		{
			swap = x[i];
			x[i] = x[small];
			x[small] = swap;
		}
		for (j = 0; j < n; j++)
			printf("%d", x[j]);
	}
	return TRUE;
}


int bubblesort(int x[], int n)
{
	int i, j, flag;
	int swap;
	flag = 1;
	for (i = 0; i < n - 1 && flag == 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i; j++)
		{
			if (x[j] > x[j + 1])
			{
				flag = 1;
				swap = x[j];
				x[j] = x[j + 1];
				x[j + 1] = swap;
			}
			for (j = 0; j < n; j++)
				printf("%d", x[j]);
		}
		if (flag == 0)
			return TRUE;
	}
}

void main()
{
	int x[50];
	int n;
	int m;
	int j;
	printf("Input the number of the numbers you want to input:\n");
	scanf("%d", &n);
	printf("Please input the numbers:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	printf("Which method you want to use?\n");
		scanf("%d", &m);
		if (m == 0)
		{
			insertsort(x, n);
			for (j = 0; j < n; j++)
				printf("%d", x[j]);
		}
		if (m == 1)
		{
			selectsort(x, n);
			for (j = 0; j < n; j++)
				printf("%d", x[j]);
		}
		if (m == 2)
		{
			bubblesort(x, n);
			for (j = 0; j < n; j++)
				printf("%d", x[j]);
		}

}
