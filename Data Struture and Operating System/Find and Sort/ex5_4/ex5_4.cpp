// ex5_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

void quicksort(int x[], int l, int r)
{
	int i, j;
	int swap;
	i = l;
	j = r;
	swap = x[l];
	while (i < j)
	{
		while (i < j&&swap <= x[j])
			j--;
		if (i < j)
		{
			x[i] = x[j];
			i++;
		}
		while (i < j&&swap >= x[i])
			i++;
		if (i < j)
		{
			x[j] = x[i];
			j--;
		}
	}
	x[i] = swap;
	if (l < i) quicksort(x, l, i - 1);
	if (i < r) quicksort(x, j + 1, r);
}

int main()
{
	int x[50];
	int n;
	int m;
	int j;
	int l, r;
	printf("Input the number of the numbers you want to input:\n");
	scanf("%d", &n);
	l = 0;
	r = n - 1;
	printf("Please input the numbers:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	quicksort(x, l, r);
	for (j = 0; j < n; j++)
		printf("%d", x[j]);
	return TRUE;
}

