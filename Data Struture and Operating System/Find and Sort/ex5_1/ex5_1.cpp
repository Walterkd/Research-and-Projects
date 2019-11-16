// ex5_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


int seq_search(int S[], int k, int n)
{
	int i;
	S[n] = k;
	i = 0;
	while (S[i] != k)
		i++;
	if (i < n)
	{
		printf("searching success");
		return (i);
	}

	else
	{
		printf("searching failed");
		return (-1);
	}

}

int bin_search(int S[8], int k, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (S[mid] == k)
		{
			printf("searching success");
			return(mid);
		}
		else if (S[mid] < k)
			low = mid + 1;
		else
			high = mid - 1;
	}
	printf("searching failed");
	return (-1);
}

int main()
{
	int x;
	int s[] = { 3, 10, 13, 17, 40, 43, 50, 70 };
	int k = 43;
	int n = 8;
	printf("input 43 0r 5");
	scanf("%d", &x);
	if (x == 43)
	{
		seq_search(s, k, n);

	}
	if (x == 5)
	{
		bin_search(s, k, n);
	}
}