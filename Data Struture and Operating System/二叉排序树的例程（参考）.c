#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int KeyType;
typedef struct		/*Ԫ�صĶ���*/
{
    KeyType key;
}DataType;
typedef struct Node	/*���������������Ͷ���*/
{
	DataType data;
	struct Node *lchild,*rchild;
}BiTreeNode,*BiTree;
void DeleteNode(BiTree *s);
int BSTDelete(BiTree *T,DataType x);
void InOrderTraverse(BiTree T);
BiTree BSTSearch(BiTree T,DataType x);
int BSTInsert(BiTree *T,DataType x);
void main()
{
	BiTree T=NULL,p;
	DataType table[]={55,43,66,88,18,80,33,21,72};
	int n=sizeof(table)/sizeof(table[0]);
	DataType x={80},s={18};
	int i;
	for(i=0;i<n;i++)
		BSTInsert(&T,table[i]);
	printf("�ؼ�������Ϊ��");
	for(i=0;i<n;i++)
		printf("%4d",table[i]);
	printf("\n");
	printf("������������������õ�������Ϊ��\n");
	InOrderTraverse(T);
	p=BSTSearch(T,x);
	if(p!=NULL)
        printf("\n��������������:Ԫ�عؼ���%d���ҳɹ�.\n",x);
    else
        printf("\n��������������:û���ҵ�Ԫ��%d.\n",x);
	BSTDelete(&T,s);
	printf("ɾ��Ԫ��%d��������������������õ�������Ϊ��\n",s.key);
	InOrderTraverse(T);
	printf("\n");
}
void InOrderTraverse(BiTree T)
/*������������������ĵݹ�ʵ��*/
{
    if(T)								/*���������������Ϊ��*/
	{
		InOrderTraverse(T->lchild);		/*�������������*/
        printf("%4d",T->data); 			/*���ʸ����*/
        InOrderTraverse(T->rchild); 		/*�������������*/
    }
}
int BSTDelete(BiTree *T,DataType x)
/*�ڶ���������T�д���ֵΪx������Ԫ��ʱ��ɾ��������Ԫ�ؽ�㣬������1�����򷵻�0 */
{ 
	if(!*T)							/*���������ֵΪx������Ԫ�أ��򷵻�0*/
		return 0;
	else
	{
		if(x.key==(*T)->data.key)			/*����ҵ�ֵΪx������Ԫ�أ���ɾ���ý��*/
			DeleteNode(T);
		else if((*T)->data.key>x.key)	/*�����ǰԪ��ֵ����x��ֵ�����ڸý����������в��Ҳ�ɾ��֮*/
			BSTDelete(&(*T)->lchild,x);
		else						/*�����ǰԪ��ֵС��x��ֵ�����ڸý����������в��Ҳ�ɾ��֮*/
			BSTDelete(&(*T)->rchild,x);
		return 1;
	}
}
void DeleteNode(BiTree *s)
/*�Ӷ�����������ɾ�����s����ʹ�ö������������ʲ���*/
{ 
	BiTree q,x,y;
	if(!(*s)->rchild)		/*���s��������Ϊ�գ���ʹs����������Ϊ��ɾ���˫�׽���������*/
	{
		q=*s;
		*s=(*s)->lchild;
		free(q);
	}
	else if(!(*s)->lchild)	/*���s��������Ϊ�գ���ʹs����������Ϊ��ɾ���˫�׽���������*/
	{
		q=*s;
		*s=(*s)->rchild;
		free(q);
	}
	else					
	/*���s���������������ڣ���ʹs��ֱ��ǰ��������s����ʹ��ֱ��ǰ��������������Ϊ��˫�׽������������*/
	{
		x=*s;
		y=(*s)->lchild;
		while(y->rchild)	/*����s��ֱ��ǰ����㣬yΪs��ֱ��ǰ����㣬xΪy��˫�׽��*/
		{
			x=y;
			y=y->rchild;
		}
		(*s)->data=y->data; 		/*���s��yȡ��*/
		if(x!=*s)				/*������s�����ӽ�㲻����������*/
			x->rchild=y->lchild; /*ʹy����������Ϊx��������*/
		else					/*������s�����ӽ�����������*/
			x->lchild=y->lchild; 	/*ʹy����������Ϊx��������*/
		free(y);
	}
}
int BSTInsert(BiTree *T,DataType x)
/*�����������Ĳ��������������в�����Ԫ��x����x���뵽��ȷ��λ�ò�����1�����򷵻�0*/
{
	BiTreeNode *p,*cur,*parent=NULL;
	cur=*T;
	while(cur!=NULL)
	{
		if(cur->data.key==x.key)	/*����������д���Ԫ��Ϊx�Ľ�㣬�򷵻�0*/
			return 0;
		parent=cur;				/*parentָ��cur��ǰ�����*/
		if(x.key<cur->data.key)		/*����ؼ���С��pָ��Ľ���ֵ�������������в���*/
			cur=cur->lchild;
		else
			cur=cur->rchild;			/*����ؼ��ִ���pָ��Ľ���ֵ�������������в���*/
	}
	p=(BiTreeNode*)malloc(sizeof(BiTreeNode));	/*���ɽ��*/
	if(!p)
		exit(-1);
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	if(!parent)						/*���������Ϊ�գ����һ����Ϊ�����*/
		*T=p;
	else if(x.key<parent->data.key)		/*����ؼ���С��parentָ��Ľ�㣬��x��Ϊparent������*/
		parent->lchild=p;
	else							/*����ؼ��ִ���parentָ��Ľ�㣬��x��Ϊparent���Һ���*/
		parent->rchild=p;
	return 1;	
}
BiTree BSTSearch(BiTree T,DataType x)
/*�����������Ĳ��ң�����ҵ�Ԫ��x���򷵻�ָ�����ָ�룬���򷵻�NULL*/
{
	BiTreeNode *p;
	if(T!=NULL)						/*���������������Ϊ��*/
	{
		p=T;
		while(p!=NULL)
		{
			if(p->data.key==x.key)	/*����ҵ����򷵻�ָ��ý���ָ��*/
				return p;
			else if(x.key<p->data.key)	/*����ؼ���С��pָ��Ľ���ֵ�������������в���*/
				p=p->lchild;
			else
				p=p->rchild;	/*����ؼ��ִ���pָ��Ľ���ֵ�������������в���*/
		}
	}
return NULL;
}
