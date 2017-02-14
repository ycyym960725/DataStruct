#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(Node)
typedef struct node Node;
struct node{
	int number;
	Node *next;
};
Node *Create(Node *L,int i){
	Node *head, *p, *s=NULL;
	int numbers =1;
	head = (Node *)malloc(LEN);
	head->next = head;
	p = head;
	while (numbers<=i)
	{
		s = p;
		p = (Node*)malloc(LEN);
		s->next = p;
		p->next = head;
		p->number = numbers++;
	}
	p->next = head->next;
	free(head);
	return (p->next);
}
void Show_List(Node *L){
	Node *head, *p;
	head = L;
	p = head;
	while (p->next!=head){
		printf("\t%d",(p->number));
		p = p->next;
	}
	printf("\t%d\n", (p->number));
}
void *Joseph(Node *L){
	Node *temp, *pb;
	pb = L;//pb��ָ���һ���ڵ�
	while (pb->next!=pb){
		for (int i=1 ;i<2 ;i++)pb = pb->next;
		printf("\t->%d", (pb->next->number));
		temp = pb->next;
		pb->next = temp->next;
		free(temp);
		pb = pb->next;
	}
	printf("\n\t\t\t��ʤ��Ϊ%d\t\t\t", pb->number);
}
void main(){
	Node *L = NULL;
	int node_count;
	printf("\n������Լɪ���Ĵ�С!\n");
	scanf_s("%d", &node_count);
	printf("\n\t\t��ʼ���ɹ�!\n");
	L = Create(L, node_count);
	Show_List(L);
	Joseph(L);
}
