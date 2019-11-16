// expand2_3_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct dl_Node
{
	int data;
	struct dl_Node *prior, *next;
}dl_Node;

int doublelist_create(dl_Node **head)
{
	int num;
	dl_Node *p = *head;
	if ((*head = (dl_Node*)malloc(sizeof(dl_Node))) == NULL)
		return FALSE;
	(*head)->data = 0;
	(*head)->prior = NULL;
	(*head)->next = NULL;
	printf("Please input:");
	while (true)
	{
		scanf("%d", &num);
		if (num == 0) break;
		p->next = (dl_Node*)malloc(sizeof(dl_Node));
		p->next->data = num;
		p->next->prior = p;
		p->next->next = NULL;

		(*head)->data++;
		p = p->next;
	}
	return TRUE;
}


void doublelist_show(dl_Node *head)
{
	printf("\n The list is:");
	dl_Node *p = head;
	while (p->next != NULL)
	{
		printf("%d", p->next->data);
		p = p->next;
	}
	printf("The length of the list is :", head->data);
}

void doublelist_sort(dl_Node *head)
{
	for (int i = 1; i < head->data; i++)
	{
		int end = 1, j = 0;
		dl_Node *p = head;
		for (; j < head->data - 1; j++)
		{
			if (p->next->data>p->next->next->data)
			{
				dl_Node *q = p->next;
				p->next = q->next;
				q->next->prior = q->prior;
				q->next = p->next->next;
				p->next->next->prior = q;
				p->next->next = q;
				q->prior = p->next;
				end = 0;
			}
			p = p->next;
		}
		if (end) break;
	}
}

int main()
{
	dl_Node *head = NULL;
	doublelist_create(&head);
	doublelist_show(head);
	doublelist_sort(head);

	return  0;
}

			

