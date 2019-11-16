// 1_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUM 20
#define true 1
#define false 0

typedef struct
{
	int data[MAXNUM];
	int length;
}list_type;

void initiallist(list_type *lp)
{
	lp->length = 0;
}

void createlist(list_type *lp)
{
	lp->length = 0;
	int i, elem;
	printf("\nPlease input the datas:\n");
	for (i = 0; i < MAXNUM; i++)
	{
		scanf("%d", &elem);
		if (elem == 250) break;
		lp->data[i] = elem;
		(lp->length)++;
	}
}

void showlist(list_type *lp)
{
	int i;
	printf("\nThe %d records are:\n");
	if (lp->length <= 0)
	{
		printf("\nNo data!\n");
		return;
	}
	for (i = 0; i < lp->length; i++)
	{
		printf(" %d ", lp->data[i]);

	}
	printf("\nThe length of of list is %d\n",lp->length);

}

void reverselist(list_type *lp)
{
	int i, n;
	n = ((lp->length) + ((lp->length) % 2)) / 2;
	int temp = 0;
	for (i = 0; i < n; i++)
	{
		temp=lp->data[i];
		lp->data[i] = lp->data[lp->length - 1 - i];
		lp->data[lp->length - 1 - i] = temp;

	}

}
int main()
{
	list_type lp;
	createlist(&lp);
	showlist(&lp);
	printf("\nThe list after reversing:\n");
	reverselist(&lp);
	showlist(&lp);
	return(true);
}

