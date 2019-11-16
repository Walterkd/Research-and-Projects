// 2_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct node_type
{
	int data;
	struct node_type *next;

}node_type;

typedef struct list_type
{
	node_type *head;
	node_type *tail;
	int length;
}list_type;

void init_list(list_type *lp)
{
	int i = 0, j = 0, x = 0;
	lp->head = NULL;
	lp->tail = NULL;
	lp->length = 0;
	printf("\nPlease input the datas you want to put in:\n");
	scanf("%d", &x);
	while (x != 0)
	{
		node_type *newdata;
		newdata = (node_type*)malloc(sizeof(node_type));
		newdata->data = x;
		newdata->next = NULL;

		if (lp->length <= 0)
		{
			lp->head = newdata;
			lp->tail = newdata;

		}

		else
		{
			(lp->tail)->next = newdata;
			lp->tail = newdata;

		}
		(lp->length)++;
		scanf("%d", &x);

	}
}

void show_list(list_type *lp)
{
	int i = 0;
	node_type *p;
	p = (node_type*)malloc(sizeof(node_type));
	p=lp->head;
	printf("\nThe datas of the list are:\n");
	for (; i < lp->length; i++)
	{
		printf("  %d  ", p->data);
		p = p->next;
	}
	printf("\n");
}

void add_list(list_type *lp, int x, int j)
{
	int i = 0;
	node_type *p;
	node_type *newdata;
	newdata = (node_type*)malloc(sizeof(node_type));
	p = lp->head;
	newdata->data = x;
	newdata->next = NULL;
	if (j == 1)
	{
		newdata->next = lp->head;
		lp->head = newdata;

	}
	else
	{
		for (i = 2; i < j; i++)
		{
			p = p->next;
		}
		newdata->next = p->next;
		p->next = newdata;
	}
	(lp->length)++;

}

void delete_list(list_type *lp, int j)
{
	int i = 0;
	node_type *p;
	node_type *m;
	p = lp->head;
	if (j == 1)
	{
		lp->head = p->next;
		/*free(p);*/
	}
	else
	{
		for (i = 2; i < j; i++)
		{
			p = p->next;
		}
		m = p->next;
		p->next = (p->next)->next;
		/*free(m);*/
	}
	(lp->length)--;
}

void judge_list(list_type *lp)
{
	int i = 0, x = 0, key = 1;
	node_type *p;
	p = lp->head;
	printf("\nPlease input the data:\n");
	scanf("%d", &x);
	for (i = 2; i <= lp->length; i++)
	{
		int m = i;
		p = p->next;
		if (p->data == x)
		{
			delete_list(lp, m);
			key = 0;
		}
	}
	if (key == 1)
	{
		add_list(lp, x, (lp->length) + 1);
	}
}

void insert_list(list_type *lp)
{
	int i = 0;
	int x = 0;
	node_type *p;
	p = lp->head;
	printf("\nPlease input the data:\n");
	scanf("%d", &x);
	if (x <= lp->head->data)
	{
		add_list(lp, x, 1);
	}
	else
	{
		for (i = 1; i < lp->length; i++)
		{
			if ((p->data <= x) && ((p->next)->data)>=x)
			{
				add_list(lp, x, i + 1);
				break;
			}
			p = p->next;
			if (i == lp->length)
			{
				add_list(lp, x, i + 1);
			}
		}
	}
}

void negative_delete(list_type *lp)
{
	int i = 0, j = 0;
	node_type *p;
	p = lp->head;
	while (lp->head->data < 0)
	{
		lp->head = lp->head->next;
		lp->length--;
	}
	p = lp->head;
	j = lp->length;
	for (i = 1; i < j; i++)
	{
		if (p->next->data < 0)
		{
			p->next = p->next->next;
			lp->length--;

		}
		else
		{
			p = p->next;
		}
	}


}
int main()
{
	int i = 0;
	int x = 0;
	list_type lp;
	init_list(&lp);
	show_list(&lp);

	judge_list(&lp);
	show_list(&lp);

	/*insert_list(&lp);
	show_list(&lp);*/

	/*negative_delete(&lp);
	show_list(&lp);*/

	return(true);
}

