#include<stdio.h>
#include<malloc.h>
#define true 1
#define false 0
int deep = 0;
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

void depthoftree(bnode_type *bt,int step) {
	if(bt == NULL) {
		if(step > deep)	deep = step;
	} else {
		depthoftree(bt -> lchild,step + 1);
		depthoftree(bt -> rchild,step + 1);

	}
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

void swaptree(bnode_type **bt1,bnode_type **bt2) {
	bnode_type *p;
	p = *bt1;
	*bt1 = *bt2;
	*bt2 = p;
}

void reversetree(bnode_type **bt) {
	if((*bt) == NULL) {
		return;
	}else{
			swaptree(&((*bt) -> lchild),&((*bt) -> rchild));
			reversetree(&((*bt) -> lchild));
			reversetree(&((*bt) -> rchild));
	}
}
int main() {
	bnode_type *bt;
	bt = NULL;
	int num[20] = {190,381,12,40,410,394,540,760,85,476,800,146,9,445,600};
	for(int i=0; i<15; i++)	input(&bt,num[i]);

	deep = 0;
	depthoftree(bt,0);
	printf("depth: %d\n",deep);

	printf("After Sort: ");
	LeftRootRight(bt);

	reversetree(&bt);
	printf("After Reverse: ");
	LeftRootRight(bt);
	return 0;
}
