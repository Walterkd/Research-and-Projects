// ex13expand.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define MAXNUM 20
#define true 1
#define false 0

typedef struct
{
	int data[MAXNUM];
	int length;
}list_type;


/*create a list:input data from keyboard,end by -1*/
void createlist(list_type *list)
{
	int i, elem;
	list->length = 0;
	printf("please input datas of the list\n");
	for (i = 0; i < MAXNUM; i++)
	{
		scanf(" %d", &elem);
		if (elem == -1) break;
		list->data[i] = elem;
		list->length++;
	}
}

/*show the elements of the list*/
void showlist(list_type *list)
{
	int i;
	printf("\nThese %d records are:\n", list->length);
	if (list->length <= 0)
	{
		printf("No data!\n");
		return;
	}
	for (i = 0; i < list->length; i++)
		printf(" %d ", list->data[i]);
	printf("\nlength of the list is:%d", list->length);
}


void reverselist(list_type *list)
{
	int n = (list->length - list->length % 2) / 2, i = 0;
	int temp_data = 0;
	for (; i < n; i++)
	{
		temp_data = list->data[i];
		list->data[i] = list->data[list->length - 1 - i];
		list->data[list->length - 1 - i] = temp_data;
	}
}


void main()
{
	list_type list;
	//int i;
	createlist(&list);
	showlist(&list);
	reverselist(&list);
	printf("\nlist after delete all negative:\n");
	showlist(&list);
	//scanf("%d", &i);
}


