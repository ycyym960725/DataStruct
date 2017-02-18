#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
typedef int Status;
typedef int SElemType;
typedef struct Node
{
	SElemType data;
	struct Node *next;
}StackNode, *PStackNode;
typedef struct LinkStack
{
	StackNode * base; //ջ��ָ��
	StackNode * top; //ջ��ָ��
} LinkStack, *PLinkStack;
Status InitLinkStack(LinkStack *s){
	s->base= (PStackNode)malloc(sizeof(StackNode));
	if (!s->base){
		printf("\n����ռ�ʧ��!\n");
		return ERROR;
	}
	s->top = s->base;
	s->base->next = NULL;
	return OK;
}
Status IsEmptyLinkStack(LinkStack *s){
	if (s->base==s->top){
		return OK;
	}
	else{
		return ERROR;
	}
}
void ClearLinkStack(LinkStack *s){
	StackNode *p,*dele;
	p = s->top;
	while (p!=s->base){
		dele = p;
		p = p->next;
		free(dele);
	}
	s->top = s->base;
}
int StackLength(LinkStack *s){
	int count = 0;
	StackNode *p = s->top;
	while (p!=s->base){
		count++;
		p = p->next;
	}
	return count;
}
Status GetTop(LinkStack *s,SElemType *e){
	if (IsEmptyLinkStack(s)){
		printf("\n��ջΪ��!\n");
		return ERROR;
	}
	StackNode *p = s->top;
	*e = p->data;
	return OK;
}
Status Push(LinkStack *s,SElemType e){
	PStackNode r = (PStackNode)malloc(sizeof(StackNode));
	if (!r){
		printf("\n�ڴ治��!\n");
		return ERROR;
	}
	r->data =e;
	r->next = s->top;
	s->top = r;
	return OK;
}
Status Pop(LinkStack *s,SElemType *e){
	StackNode *p;
	if (s->top==s->base){
		printf("\n��ջ�ѿ�!\n");
		return ERROR;
	}
	p = s->top;
	*e = p->data;
	s->top = p->next;
	free(p);
	return OK;
}
void TrasverLinkStack(LinkStack *s)
{
	if (IsEmptyLinkStack(s))
	{
		printf("��ջ\n");
		exit(-1);
	}

	StackNode *p = s->top;
	while (p != s->base)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
}
void DestroyLinkStack(LinkStack *s){
	StackNode *p = s->top,*dele;
	while (p!=s->base){
		dele = p;
		p = p->next;
		free(dele);
	}
	dele = s->base;
	s->base = s->top = NULL;
	free(dele);
	printf("\nջ������!\n");
}
void main(){
	LinkStack s;
	SElemType e;
	if (InitLinkStack(&s)){
		printf("\n��ʼ���ɹ�!\n");
	}
	else{
		printf("\n��ʼ��ʧ��!\n");
	}
	printf("ջ��Ԫ�صĸ���: %d\n", StackLength(&s));
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	Push(&s, 4);
	Push(&s, 5);
	Push(&s, 6);
	printf("��ջ�ɹ�!\n");
	printf("---ջ��Ԫ�صĸ���: %d\n", StackLength(&s));
	TrasverLinkStack(&s);
	printf("---���ջ\n");
	ClearLinkStack(&s);
	printf("---ջ��Ԫ�صĸ���: %d\n", StackLength(&s));
	Push(&s, 2);
	Push(&s, 4);
	Push(&s, 5);
	Push(&s, 6);
	Push(&s, 8);
	Push(&s, 9);
	printf("��ջ�ɹ�!\n");
	printf("---ջ��Ԫ�صĸ���: %d\n", StackLength(&s));
	TrasverLinkStack(&s);
	GetTop(&s, &e);
	printf("--ջ��Ԫ��: %d\n", e);
	while (!IsEmptyLinkStack(&s)){
		Pop(&s, &e);
		printf("%d��ջ\n", e);
	}
	printf("---ջ��Ԫ�صĸ���: %d\n", StackLength(&s));
	DestroyLinkStack(&s);
	GetTop(&s, &e);
}