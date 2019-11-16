// 3_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUM 6

typedef struct dhStack_type
{
	int top1;
	int top2;
	int data[MAXNUM];

}dhStack_type;

void push_dhStack(dhStack_type *dhStack, int x)
{
	int i = 0;
	if (dhStack->top1 > dhStack->top2)
	{
		printf("\nThe stack is full!\n");
		r
	}
	else
	{
		printf("\nPlease choose which stack:\n");
		scanf("%d", &i);
	}
	if (i == 1)
	{
		dhStack->data[dhStack->top1] = x;
		dhStack->top1++;
	}
	if (i == 2)
	{
		dhStack->data[dhStack->top2] = x;
		dhStack->top2--;
	}
}

void init_dhStack(dhStack_type *dhStack)
{
	int x = 0;
	printf("\nPlease input the numbers:\n");
	scanf("%d", &x);
	while (x != 1)
	{
		push_dhStack(dhStack, x);
		printf("\nPlease input the number:\n");
		scanf("%d", &x);
		
	}
}

void show_dhStack(dhStack_type *dhStack)
{
	int i = 0, j = 0;
	printf("\nThe first stack is:\n");
	for (; i < dhStack->top1; i++)
	{
		printf("  %d  ", dhStack->data[i]);
	}
	printf("\nThe second stack is:\n");
	for (j = MAXNUM - 1; j > dhStack->top2; j--)
	{
		printf("  %d  ", dhStack->data[j]);
	}
}

void pop_dhStack(dhStack_type *dhStack)
{
	int i = 0;
	printf("\nWhich stack you want operate:\n");
	scanf("%d", &i);
	if (i == 1)
	{
		if (dhStack->top1 == 0)
		{
			printf("\n The first stack is empty!\n");

		}
		else
		{
			printf("\n %d is poped out of stack", dhStack->data[dhStack->top1 - 1]);
			dhStack->top1--;
		}
	}
	else if (i == 2)
	{
		if (dhStack->top2 == MAXNUM-1)
		{
			printf("\n THe second stack is empty!\n");
		}
		else
		{
			printf("\n %d is poped out of stack", dhStack->data[dhStack->top2 + 1]);
			dhStack->top2++;
		}
	}
}

int main()
{
	int x = 0;

	dhStack_type dhStack;

	(&dhStack)->top1 = 0;
	(&dhStack)->top2 = MAXNUM - 1;

	init_dhStack(&dhStack);
	printf("\n after initing\n");
	show_dhStack(&dhStack);

	printf("\nPlease input the data:\n");
	scanf("%d", &x);
	push_dhStack(&dhStack, x);

	pop_dhStack(&dhStack);

	printf("\nPlease input the data:\n");
	scanf("%d", &x);
	push_dhStack(&dhStack, x);

	show_dhStack(&dhStack);

	while (1)
	{
		pop_dhStack(&dhStack);
		show_dhStack(&dhStack);
	}
    return(true);
}

