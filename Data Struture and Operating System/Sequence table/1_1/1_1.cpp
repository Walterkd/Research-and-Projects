// 1_1.cpp : 定义控制台应用程序的入口点。
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

void initiatelist(list_type *l)
{
	l->length = 0;
}

void createlist(list_type *lp)
{
	int i, elem;
	initiatelist(lp);
	printf("\n Please input the datas of the list\n");
	for (i = 0; i <= MAXNUM - 1; i++)
	{
		scanf("%d", &elem);
		if (elem == -1) break;
		lp->data[i] = elem;
		lp->length++;
	}
}

void showlist(list_type *lp)
{
	int i;
	printf("\nThe %d numbers are:\n", lp->length);
	if (lp->length <= 0)
	{
		printf("There is no data!\n");
		return;
	}
	if (lp->length > 0)
	{
		for (i = 0; i < lp->length; i++)
		{
			printf(" %d ", lp->data[i]);
		}
		printf("The length of the list is %d", lp->length);
	}

}

int insertlist(list_type *lp, int i, int x)
{
	int j;
	if (lp->length >= MAXNUM)
	{
		printf("The list is full, can not insert.");
		return(false);
	}
	if ((i<0) || (i>lp->length))
	{
		printf("i is invalid value");
		return(false);
	}
	for (j = (lp->length) - 1; j >= i; j--)
	{
		lp->data[j + 1] = lp->data[j];
	}
	lp->data[i] = x;
	(lp->length)++;
	return(true);
}

int deletelist(list_type *lp, int i)
{
	int  j;
	if ((i<0) || (i>(lp->length)))
	{
		printf("Not exist!");
		return(false);
	}
	for (j = i; j < lp->length; j++)
	{
		lp->data[j - 1] = lp->data[j];
	}
	(lp->length)--;
	return(true);
}



void main()
{
	list_type lp;
	int i, data;
	
	createlist(&lp);
	showlist(&lp);
	printf("\ninsert:Enter i and data:\n");
	scanf("%d", &i);
	scanf("%d", &data);
	insertlist(&lp, i, data);
	printf("\nlist after insert:\n");
	showlist(&lp);
	printf("\ndelete:Enter i:\n");
	scanf("%d", &i);
	deletelist(&lp, i);
	printf("\nlist after delete:\n");
	showlist(&lp);

	return;
}

