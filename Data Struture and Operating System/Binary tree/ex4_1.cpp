#include<stdio.h>
#include<malloc.h>
#define true 1
#define false 0
typedef struct bnode {
	int data;
	struct bnode *lchild, *rchild;
} bnode_type;

void init(bnode_type *bt) {
	bt -> lchild = NULL;
	bt -> rchild = NULL;
}

void input(bnode_type **bt,int x) {
	if((*bt) == NULL) {
		bnode_type *p;
		p = (bnode_type*)malloc(sizeof(bnode_type));
		p -> data = x;
		init(p);
		*bt = p;
		return;
	}
	if(x < (*bt) -> data) {
//		printf("l %d\n",x);
		input(&((*bt) -> lchild), x);
	} else {
//		printf("r %d\n",x);
		input(&((*bt) -> rchild), x);
	}
}

void RootLeftRight(bnode_type *bt) {
	bnode_type *p = bt;
	bnode_type* s[505];
	int count = 0;
	while (count != 0 || p != NULL) {
		while (p != NULL) {
			s[count++] = p;
			printf("%d ",p->data);
			p = p -> lchild;
		}
		if (count != 0) {
			p = s[--count];
			p = p -> rchild;
		}
	}
	printf("\n");
}

void LeftRootRight(bnode_type *bt) {
	bnode_type *p = bt;
	bnode_type* s[505];
	int count = 0;
	while (count != 0 || p != NULL) {
		while (p != NULL) {
			s[count++] = p;
			p = p -> lchild;
		}
		if (count != 0) {
			p = s[--count];
			printf("%d ",p->data);
			p = p -> rchild;
		}
	}
	printf("\n");
}

void LeftRightRoot(bnode_type *bt) {
	if(bt == NULL)	return;
	if(bt -> lchild != NULL)	LeftRightRoot(bt -> lchild);
	if(bt -> rchild != NULL)	LeftRightRoot(bt -> rchild);
	printf("%d ",bt -> data);
}

int main() {
	bnode_type *bt;
	bt = NULL;
	int num[20] = {190,381,12,40,410,394,540,760,85,476,800,146,9,445,600};
	for(int i=0; i<15; i++)	input(&bt,num[i]);
	
	printf("Root_Left_Right: ");
	RootLeftRight(bt);
	printf("Left_Root_Right: ");
	LeftRootRight(bt);
	printf("Left_Right_Root: ");
	LeftRightRoot(bt);
	printf("\n");
	
	return 0;
}
