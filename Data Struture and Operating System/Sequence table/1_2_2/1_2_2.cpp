// 1_2_2.cpp : 定义控制台应用程序的入口点。
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

void createlist(list_type *lp)
{
	int i, elem;
	lp->length = 0;
	printf("\nPlease input the datas of the list:\n");
	for (i = 0; i < MAXNUM; i++)
	{
		scanf("%d", &elem);
		if (elem == 99) break;
		lp->data[i] = elem;
		lp->length++;
	}
}

void showlist(list_type *lp)
{
	int i;
	printf("\nThe %d records are:\n");
	for (i = 0; i < lp->length; i++)
	{
		printf(" %d ", lp->data[i]);
	}
	printf("\nThe length of the list is %d\n", lp->length);
}

void negative_dalete(list_type *lp)
{
	int i=0,j=0;
	for (; i <= lp->length; i++)
	{
		lp->data[i] < 0 ? j++ : lp->data[i - j] = lp->data[i];
		lp->length -= j;

	}

}
int main()
{
	list_type lp;
	createlist(&lp);
	showlist(&lp);
	printf("\nThe list after deleting:\n");
	negative_dalete(&lp);
	showlist(&lp);
	return(true);
}

