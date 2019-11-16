// 3_1.cpp : 定义控制台应用程序的入口点。
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

typedef struct lstack_type
{
	node_type *top;
	int length;
}lstack_type;

void push_stack(lstack_type *stack, int x)
{
	node_type *p;
	p = (node_type*)malloc(sizeof(node_type));
	p->next = stack->top;
	p->data = x;
	stack->top = p;
	stack->length++;
}

void init_stack(lstack_type *stack)
{
	int x;
	printf("\nPlease input the data:\n");
	scanf("%d", &x);
	while (x != 0)
	{
		push_stack(stack, x);
		scanf("%d", &x);

	}
}

node_type *pop_stack(lstack_type *stack)
{
	node_type *temp;
	if (stack->top == NULL)
		return NULL;
	else
	{
		temp = stack->top;
		stack->top = temp->next;
		stack->length--;
		return temp;
	}
}

void show_stack(lstack_type *stack)
{
	int i = 0;
	node_type *temp = NULL;
	temp = stack->top;
	for (; i < stack->length; i++)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
}

int main()
{
	lstack_type stack;
	(&stack)->length = 0;
	(&stack)->top = NULL;

	init_stack(&stack);
	printf("\nInit succeess!\n");
	show_stack(&stack);

	printf("\nPush one data out\n");
	pop_stack(&stack);
	show_stack(&stack);
	
	printf("\nPush one data out\n");
	pop_stack(&stack);
	show_stack(&stack);

    return(true);
}

