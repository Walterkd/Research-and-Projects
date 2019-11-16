/*栈的链式表示和实现*/
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
typedef int Elemtype;
typedef struct stacknode {
	Elemtype data;
	struct stacknode * next;
}StackNode;
typedef struct  {
	StackNode * top; //栈顶指针
}LinkStack;
/*初始化链栈*/
void InitStack(LinkStack * s)
{
	s->top = NULL;
	printf("\n已经初始化链栈！\n");
}
/*链栈置空*/
void setEmpty(LinkStack * s)
{
	s->top = NULL;
	printf("\n链栈被置空！\n");
}
/*入栈*/
void pushLstack(LinkStack * s, Elemtype x)
{
	StackNode * p;
	p = (StackNode *)malloc(sizeof(StackNode));  //建立一个节点。
	p->data = x;
	p->next = s->top;    //由于是在栈顶pushLstack，所以要指向栈顶。
	s->top = p;          //插入
}
/*出栈*/
Elemtype popLstack(LinkStack * s)
{
	Elemtype x;
	StackNode * p;
	p = s->top;          //指向栈顶
	if (s->top == 0)
	{
		printf("\n栈空，不能出栈！\n");
		return (0);
		//exit(-1);
	}
	x = p->data; printf("\n当前出栈的数据是：%d", x);
	s->top = p->next;    //当前的栈顶指向原栈的next
	free(p);           //释放
	return x;
}
/*取栈顶元素*/
Elemtype StackTop(LinkStack *s)
{
	Elemtype x;
	if (s->top == 0)
	{
		printf("\n链栈空\n");
		return (0);
	}
		{x = s->top->data; printf("\n\n当前链栈的栈顶元素为：%d\n", x); return(x); }
}
/*遍历链栈*/
void Disp(LinkStack * s)
{
	printf("\n链栈中的数据为：\n");
	printf("=======================================\n");
	StackNode * p;
	p = s->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("=======================================\n");
}
void main()
{
	int i, n, a;//int m;
	LinkStack * s;
	s = (LinkStack *)malloc(sizeof(LinkStack));
	int cord;
	printf("第一次使用必须初始化！\n");
	do{
		printf("\n");
		printf("\n");
		printf("\n ========= 主菜单===========\n");
		printf("\n     1     初始化链栈      \n");
		printf("\n     2     入栈            \n");
		printf("\n     3     出栈            \n");
		printf("\n     4     取栈顶元素      \n");
		printf("\n     5     置空链栈        \n");
		printf("\n     6     结束程序运行    \n");
		printf("\n===========================\n");
		printf("请输入您的选择( 1, 2, 3, 4, 5,6)");
		scanf_s("%d", &cord);
		printf("\n");
		switch (cord)
		{
		case 1:
		{   InitStack(s);
		Disp(s);
		}break;
		case 2:
		{printf("输入将要压入链栈的数据的个数：n=");
		scanf_s("%d", &n);
		printf("依次将%d个数据压入链栈：\n", n);
		for (i = 1; i <= n; i++)
		{
			scanf_s("%d", &a);
			pushLstack(s, a);
		}
		Disp(s);
		}break;
		case 3:
		{	//printf("\n出栈操作开始!\n");
			//printf("输入将要出栈的数据个数：m=");
			//scanf("%d",&m);
			//for(i=1;i<=m;i++)
			//{printf("\n第%d次出栈的数据是：%d",i,popLstack(s));}
			popLstack(s); Disp(s);
		}break;
		case 4:
		{	//printf("\n\n链栈的栈顶元素为：%d\n",StackTop(s));
			StackTop(s); printf("\n");
		}break;
		case 5:
		{	setEmpty(s);
		Disp(s);
		}break;
		case 6:
			exit(0);
		}
	} while (cord <= 6);
}

