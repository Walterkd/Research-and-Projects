// 2_1.cpp : 定义控制台应用程序的入口点。
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
	lp->head = NULL;
	lp->tail = NULL;
	lp->length = 0;
	int x = 0;
	printf("\nPlease input the datas stopped by inputing -1\n");
	scanf("%d", &x);
	while (x != -1)
	{
		node_type *new_node;
		new_node = (node_type*)malloc(sizeof(node_type));
		new_node->data = x;
		new_node->next = NULL;

		if (lp->length <= 0)
		{
			lp->head = new_node;
			lp->tail = new_node;

		}
		else
		{
			lp->tail->next = new_node;
			lp->tail = new_node;

		}
		lp->length++;
		scanf("%d", &x);

	}
}

void show_list(list_type *lp)
{
	node_type *temp;
	int i = 0;
	temp = lp->head;
	for (; i < lp->length; i++)
	{
		printf("\t%d", temp->data);
		temp = temp->next;
	}
}

void insert_list(list_type *lp)
{
	int i = 0, j = 0, x = 0;
	node_type *p;
	node_type *newdata;
	printf("\nPlease input the location and number of the data:\n");
	scanf("%d", &j);
	scanf("%d", &x);
	newdata = (node_type*)malloc(sizeof(node_type));
	newdata->data = x;
	p = lp->head;
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
	lp->length++;
}

void delete_list(list_type *lp)
{
	int i = 0, j = 0;
	node_type *p;
	node_type *temp;
	p = (node_type*)malloc(sizeof(node_type));
	temp = (node_type*)malloc(sizeof(node_type));
	p = lp->head;
	printf("\nPlease input the location of the data you want to delete:\n");
	scanf("%d", &j);
	if (j == 1)
	{
		lp->head = (lp->head)->next;
		free(p);
		
	}

	else
	{
		for (i = 2; i < j; i++)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = (p->next)->next;
		free(temp);
	}
}
int main()
{
	list_type lp;
	init_list(&lp);
	show_list(&lp);
	insert_list(&lp);
	show_list(&lp);
	delete_list(&lp);
	show_list(&lp);

	return(true);

}

