// ex122expand.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// ex1basic.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MAXNUM 20
#define TRUE 1
#define FALSE 0

typedef struct
{
	int data[MAXNUM];
	int length;
}list_type;

/*create a list: input data from keyboard, end by -1*/
void createlist(list_type *list)
{
	int i, elem;
	list->length = 0;
	printf("Please input the datas of the list\n");
	for (i = 0; i < MAXNUM; i++)
	{
		scanf("%d", &elem);
		if (elem == -1) break;
		list->data[i] = elem;
		list->length++;
	}

}

/*show the elements of the list*/
void showlist(list_type *list)
{
	int i;
	printf("\nThese %d elements are:\n", list->length);
		if (list->length <= 0)
		{
			printf("No data!\n");
			return;
		}
	for (i = 0; i < list->length; i++)
		printf("%d", list->data[i]);
	printf("\n The length of the list is %d", list->length);

}

void delete_negative(list_type *list)
{
	int i = 0, j = 0;
	for (; i < list->length; i++)
		list->data[i] < 0 ? j++ : list->data[i - j] = list->data[i];
	list->length -= j;

}

void main()
{
	list_type list;
	createlist(&list);
	showlist(&list);
	delete_negative(&list);
	printf("\n list after deleting all the negative numbers:\n");
	showlist(&list);

}