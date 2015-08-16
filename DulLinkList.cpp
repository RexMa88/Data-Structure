#include<iostream>
#include<stdio.h>
using namespace std;

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct DulNode{
	ElemType data;//data
	DulNode *prior;
	DulNode *next;
}DulNode,*DulLinkList;

/*Status GetElem(DulLinkList *L, int i, DulNode e){

}*/

Status createDulLinkList(DulLinkList *L,int n){
	DulLinkList p,q;
	*L = (DulLinkList)malloc(sizeof(DulNode));
	int i;
	srand(time_t(0));
	q = (*L);
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (DulLinkList)malloc(sizeof(DulNode));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		p->prior = (*L);
		(*L)->next = p;
		if (i == (n-1) )
		{
			p->next = q;
			q->prior = p;
		}
	}
	return OK;
}

int main(){
	DulLinkList L;
	int n;
	printf("The count is ");
	scanf_s("%d", &n);
	Status status = createDulLinkList(&L, n);
	printf("The status is %d", status);
	return 0;
}