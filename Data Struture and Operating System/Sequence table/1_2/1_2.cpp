// 1_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define MAXNUM 20

typedef struct
{
	int data[MAXNUM] = { 1,3,4,6,9,15,17,26,66 };
	int length=9;
}list_type;

void showlist(list_type *lp)
{
	int i;
	printf("\nThe %d records are:\n", lp->length);
	for (i = 0; i < lp->length; i++)
	{
		printf(" %d ", lp->data[i]);

	}
	printf("\nThe length of the list is %d", lp->length);
	return;
}

int insertlist(list_type *lp, int x)
{
	int i = (lp->length) - 1;
	if ((lp->length)>=MAXNUM)
	{
		printf("\nThe list is full!\n");
		return(false);
	}
	for (; i >= 0 && lp->data[i] > x; i--)
	{
		lp->data[i + 1] = lp->data[i];
	}
	lp->data[i + 1] = x;
	(lp->length)++;
	return(true);

}
int main()
{
	list_type lp;
	int new_data;
	showlist(&lp);
	printf("\nPlease input the data you want to insert:\n");
	scanf("%d", &new_data);
	insertlist(&lp, new_data);
	printf("\nThe list after inserting:\n");
	showlist(&lp);
	return(true);


}

