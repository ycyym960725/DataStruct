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
	StackNode * base; //栈底指针
	StackNode * top; //栈顶指针
} LinkStack, *PLinkStack;
Status InitLinkStack(LinkStack *s){
	s->base= (PStackNode)malloc(sizeof(StackNode));
	if (!s->base){
		printf("\n申请空间失败!\n");
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
		printf("\n该栈为空!\n");
		return ERROR;
	}
	StackNode *p = s->top;
	*e = p->data;
	return OK;
}
Status Push(LinkStack *s,SElemType e){
	PStackNode r = (PStackNode)malloc(sizeof(StackNode));
	if (!r){
		printf("\n内存不足!\n");
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
		printf("\n该栈已空!\n");
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
		printf("空栈\n");
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
	printf("\n栈已销毁!\n");
}
void main(){
	LinkStack s;
	SElemType e;
	if (InitLinkStack(&s)){
		printf("\n初始化成功!\n");
	}
	else{
		printf("\n初始化失败!\n");
	}
	printf("栈中元素的个数: %d\n", StackLength(&s));
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	Push(&s, 4);
	Push(&s, 5);
	Push(&s, 6);
	printf("入栈成功!\n");
	printf("---栈中元素的个数: %d\n", StackLength(&s));
	TrasverLinkStack(&s);
	printf("---清空栈\n");
	ClearLinkStack(&s);
	printf("---栈中元素的个数: %d\n", StackLength(&s));
	Push(&s, 2);
	Push(&s, 4);
	Push(&s, 5);
	Push(&s, 6);
	Push(&s, 8);
	Push(&s, 9);
	printf("入栈成功!\n");
	printf("---栈中元素的个数: %d\n", StackLength(&s));
	TrasverLinkStack(&s);
	GetTop(&s, &e);
	printf("--栈顶元素: %d\n", e);
	while (!IsEmptyLinkStack(&s)){
		Pop(&s, &e);
		printf("%d出栈\n", e);
	}
	printf("---栈中元素的个数: %d\n", StackLength(&s));
	DestroyLinkStack(&s);
	GetTop(&s, &e);
}