// expand2_2_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Listnode;
typedef struct List {
	Node *head;
	int length;
}listtype;

void create_List()
{
	int x;
	listtype *p;
	Node *h;
	h = p->head;
	p->head = (Node*)malloc(sizeof(Node));
	p->head->next = NULL;
	scanf("%d", &x);
	while (x)
	{
		scanf("%d", &x);
		h->next = (Node*)malloc(sizeof(Node));
		h->next->data = x;
		h = h->next;

	}


}


