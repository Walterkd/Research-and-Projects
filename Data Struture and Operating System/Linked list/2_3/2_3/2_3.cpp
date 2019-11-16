// 2_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct dl_node_type
{
	int data;
	struct dl_node_type *prior, *next;

}dl_node_type;

typedef struct dl_list_type
{
	int length;
	dl_node_type *head;
	dl_node_type *tail;

}dl_list_type;

void init_list(dl_list_type *lp)
{
	lp->length = 0;
	int x;
	dl_node_type *newdata;
	dl_node_type *p=NULL;

	printf("\nPlease input the datas:\n");
	scanf("%d", &x);
	while (x != -1)
	{
		if (lp->length <= 0)
		{
			newdata = (dl_node_type*)malloc(sizeof(dl_node_type));
			newdata->data = x;
			newdata->next = NULL;
			newdata->prior = NULL;
			lp->head = newdata;
			lp->tail = newdata;
			p = newdata;
			lp->length++;
		}
		else
		{
			newdata = (dl_node_type*)malloc(sizeof(dl_node_type));
			newdata->data = x;
			newdata->next = NULL;
			newdata->prior = p;
			lp->tail = newdata;
			p->next = newdata;
			p = newdata;
			lp->length++;

		}
		scanf("%d", &x);
	}
}

void show_list(dl_list_type *lp)
{
	int i = 0;
	dl_node_type *temp;
	temp = lp->head;
	if (lp->length == 0)
	{
		printf("\nThis is fucking empty!\n");
	}
	else
	{
		for (; i < lp->length; i++)
		{
			printf("%d\t", temp->data);
			temp = temp->next;

		}
		printf("\n");
	}
}

void bubblesort_list(dl_list_type *lp)
{
	int i = 0, j = 0;
	dl_node_type *p, *temp;
	p = lp->head;
	for (i = 1; i < lp->length; i++)
	{
		for (j = 1; j < lp->length; j++)
		{
			if (p->data > (p->next)->data)
			{
				temp = p->next;
				if (p->prior != NULL)
				{
					p->prior->next = temp;
					temp->prior = p->prior;
				}
				else
				{
					temp->prior = NULL;
				}
				if (temp->next != NULL)
				{
					p->next = temp->next;
					temp->next->prior = p;

				}
				else
				{
					p->next = NULL;
				}
				temp->next = p;
				p->prior = temp;

			}
			else
			{
				p = p->next;
			}
		}
		for (j = 1; j < lp->length; j++)
		{
			p = p->prior;
		}
	}
	lp->head = p;
}
int main()
{
	dl_list_type lp;
	init_list(&lp);
	show_list(&lp);

	printf("\nThe list after sorting:\n");
	bubblesort_list(&lp);
	show_list(&lp);

    return(true);
}

