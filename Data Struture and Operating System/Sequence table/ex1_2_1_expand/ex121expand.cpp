// ex12expand.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define MAXNUM 20
#define TRUE 1
#define FALSE 0
typedef struct {
	int data[MAXNUM] = { 3, 5, 9, 14, 18, 34, 56, 77 };
	int length = 8;
}list_type;

void showlist(list_type *list)
{
	printf("/nThis list has %d elements, and they are:", list->length);
	for (int i = 0; i < list->length; i++)
		printf("%d", list->data[i]);
	printf("The length of the list is %d \n", list->length);
}

int insertlist(list_type *list, int new_data)
{
	int i = list->length - 1;
	if (list->length >= MAXNUM)
	{
		printf("\nInvalid operation! The list is full!");
		return(FALSE);
	}
	
	for (; i >= 0 && list->data[i]>new_data; i--)
		list->data[i + 1] = list->data[i];
		list->data[i + 1] = new_data;
		list->length++;
		return(TRUE);
	
}

void main()
{
	list_type list;
	int new_data;
	showlist(&list);
	printf("\nPlease input the value of the element you want to insert: ");
	scanf("%d\n", &new_data);
	insertlist(&list, new_data);
	showlist(&list);
	scanf("%d\n", &new_data);
}
