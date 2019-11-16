// ex1basic.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

#define MAXNUM 20
#define true 1
#define false 0

typedef struct
{
	int data[MAXNUM];
	int length;
}list_type;


/*create a list:input data from keyboard,end by -1*/
void createlist(list_type *lp)
{
	int i, elem;
	lp->length = 0;
	printf("please input datas of the list\n");
	for (i = 0; i< MAXNUM; i++)
	{
		scanf(" %d", &elem);
		if (elem == -1) break;
		lp->data[i] = elem;
		lp->length++;
	}
}

/*show the elements of the list*/
void showlist(list_type *lp)
{
	int i;
	printf("\nThese %d records are:\n", lp->length);
	if (lp->length <= 0)
	{
		printf("No data!\n");
		return;
	}
	for (i = 0; i<lp->length; i++)
		printf(" %d ", lp->data[i]);
	printf("\nlength of the list is:%d", lp->length);
}

/*insert new element*/
int insertlist(list_type *lp, int new_elem, int i)
{
	int j;
	if (lp->length >= MAXNUM)
	{
		printf("the list is full,can not insert.");
		return(false);
	}
	if (i<1 || i>lp->length + 1)
	{
		printf("\n%d is invalid value", i);
		return(false);
	}
	for (j = lp->length; j >= i; j--)
		lp->data[j] = lp->data[j - 1];
	lp->data[i - 1] = new_elem;				//放入新元素;
	lp->length++;							//表长度增加;
	return(true);
}

//delete one element of the list
int deletelist(list_type *lp, int i)
{
	if (i<1 || i>lp->length)
	{
		printf("elem not exist");
		return(false);
	}
	if (i<lp->length)
		for (; i<lp->length - 1; i++)
			lp->data[i - 1] = lp->data[i];
	lp->length--;							//表长度减少;
	return(true);
}


void delete_negative(list_type *lp)
{
int i=0;
for (; i < lp->length;)
	if (lp->data[i] < 0)
		deletelist(lp, i+1);
	else
		i++;
}


void main()
{
	list_type list;
	int i, data;
	createlist(&list);
	showlist(&list);
	printf("\ninsert:Enter new_ele and i :\n");
	scanf("%d%d", &data, &i);
	insertlist(&list, data, i);
	printf("\nlist after insert:\n");
	showlist(&list);
	printf("\ndelete:Enter i:\n");
	scanf("%d", &i);
	deletelist(&list, i);
	printf("\nlist after delete:\n");
	showlist(&list);
	//scanf("%d",&i);
	delete_negative(&list);
	printf("\nlist after delete all negative:\n");
	showlist(&list);
	scanf("%d", &i);
}
