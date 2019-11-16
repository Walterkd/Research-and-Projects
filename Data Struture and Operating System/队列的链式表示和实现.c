/*实验11.2.4  队列的链式表示和实现*/
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct Qnode
{
	ElemType data;
	struct Qnode *next;
}Qnodetype;
typedef struct
{
	Qnodetype *front;
	Qnodetype *rear;
}Lqueue;
void Lappend(Lqueue *q, int x);
/*初始化并建立链队列*/
void creat(Lqueue *q)
{
	Qnodetype *h;
	int i, n, x;
	printf("输入将建立链队列元素的个数：n= ");
	scanf_s("%d", &n);
	h = (Qnodetype*)malloc(sizeof(Qnodetype));
	h->next = NULL;
	q->front = h;
	q->rear = h;
	for (i = 1; i <= n; i++)
	{
		printf("链队列第%d个元素的值为：", i);
		scanf_s("%d", &x);
		Lappend(q, x);
	}
}
/*入链队列*/
void Lappend(Lqueue *q, int x)
{
	Qnodetype *s;
	s = (Qnodetype*)malloc(sizeof(Qnodetype));
	s->data = x;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
}
/*出链队列*/
ElemType Ldelete(Lqueue *q)
{
	Qnodetype *p;
	ElemType x;
	if (q->front == q->rear)
	{
		printf("队列为空!\n");
		return 0;
	}
	else
	{
		p = q->front->next;
		q->front->next = p->next;
		if (p->next == NULL)
			q->rear = q->front;
		x = p->data;
		free(p);
	}
	printf("出链队列元素：%d\n", x); return(x);
}
/*遍历链队列*/
void display(Lqueue *q)
{
	Qnodetype *p;
	p = q->front->next;      /*指向第一个数据元素节点 */
	if (!p)	printf("队列为空!\n");
	else
	{
		printf("\n链队列元素依次为：");
		while (p != NULL)
		{
			printf("%d-->", p->data);
			p = p->next;
		}
		printf("\n\n遍历链队列结束！ \n");
	}
}
void main()
{
	Lqueue *p;
	int x, cord;
	p = (Lqueue *)malloc(sizeof(Lqueue));
	printf("\n*****第一次操作请选择初始化并建立链队列！*****\n ");
	do
	{
		printf("=================主菜单 ===================\n");
		printf("      1    初始化并建立链队列     \n");
		printf("      2    入链队列               \n");
		printf("      3    出链队列               \n");
		printf("      4    遍历链队列             \n");
		printf("      5    结束程序运行           \n");
		printf("==========================================\n");
		scanf_s("%d", &cord);
		switch (cord)
		{
		case 1:
		{	creat(p);
		display(p);
		}break;
		case 2:
		{	printf("请输入队列元素的值：x=");
		scanf_s("%d", &x);
		Lappend(p, x);
		display(p);
		}break;
		case 3:
		{	Ldelete(p);
		display(p);
		}break;
		case 4:
		{display(p); }break;
		case 5:
		{exit(0); }
		}
	} while (cord <= 5);
}

