#include <stdio.h>
#include <stdlib.h>
#define Status int
#define OK 1
#define ERROR -1
#define LEN sizeof(Node)
typedef struct node Node;
struct node{
	int data;
	struct node *next;
};
Node *ds_init(int n){
	Node *head, *rear,*L,*p;
	head = NULL;
	L = (Node*)malloc(LEN);
	head = L;
	L->next = head;
	p = L->next;
	rear = p;
	for (int i = 1; i <= n; i++)
	{
		p = (Node*)malloc(LEN);
		p->data = i;
		p->next = rear->next;//尾指针的next始终是指向头结点的
		rear->next = p;
		rear = p;
	}
	return head;
}
int Node_Nums(Node *L){
	int count = 0;
	Node *p,*head;
	p = L;
	head = L;
	p = p->next;
	while (p!=head)
	{
		count++;
		p = p->next;
	}
	return count;
}
Status ds_insert(Node *L,int i){
	Node *head,*pf,*pb,*new1;
	head = L;
	int count = 1;
	pb = L->next;//取得第一个元素节点
	pf = pb;
	if (L->next==head)
	{
		printf("\n该表为空表!\n");
		exit(ERROR);
	}
	if (i<1||i>Node_Nums(L)+1)
	{
		printf("\n插入位置有误!\n");
		exit(ERROR);
	}
	while (pb!=head&&count<i)
	{	
		count++;
		pf = pb;
		pb = pb->next;
	}
	if (count>=i){
		new1 = (Node*)malloc(LEN);
		printf("\n请输入新节点的数据\n");
		scanf_s("%d", &(new1->data));
		new1->next = pf->next;
		pf->next = new1;
		return OK;
	}


}
Status ds_delete(Node *L,int i){
	Node *head, *pf, *pb;
	head = L;
	pf = head;
	pb = head->next;//拿到第一个元素节点
	int count = 1;
	if (L->next==head)
	{
		printf("\n该表为空表!\n");
	}
	if (i<1||i>Node_Nums(L))
	{
		printf("\n删除位置有误\n");
		exit(ERROR);
	}
	while (pb->next!=head&&count<i){
		pf = pb;
		count++;
		pb = pb->next;
	}
	pf->next = pf->next->next;
	free(pb);
	return OK;
}
void Show_ds_list(Node *L){
	Node *head, *pb;
	int count = 1;
	head = L;
	pb = head;
	pb = pb->next;
	while (pb!=head){
		printf("%d号节点的数据为%d\n",count,pb->data);
		count++;
		pb = pb->next;
	}
}
Status GetNode(Node *L,int i){
	Node *head, *pb;
	int elem;
	int position=1;
	head = L;
	pb = head->next;
	if (pb==head){
		printf("\n该表是空表!\n");
	}
	while (pb){
		if (pb->data==i){
			return position;
		}
		pb = pb->next;
		position++;
	}
	return ERROR;
}
void main(){
	Node *L = NULL;
	int count;
	int insert_position;
	int delete_position;
	int elem;
	printf("\n请输入要创建节点的个数!\n");
	scanf_s("\n%d", &count);
	L = ds_init(count);
	printf("\n创建成功! 表中共含%d个节点\n",Node_Nums(L));
	Show_ds_list(L);
	printf("\n请输入要插入的位置\n");
	scanf_s("%d", &insert_position);
	if (ds_insert(L,insert_position)==1)
	{
		printf("\n插入成功\n");
		Show_ds_list(L);
	}
	printf("\n请输入要删除的位置\n");
	scanf_s("%d",&delete_position);
	if (ds_delete(L,delete_position)==1){
		printf("\n删除成功!\n");
		Show_ds_list(L,delete_position);
	}
	printf("\n请输入想要查找的节点的数据!\n");
	scanf_s("%d", &elem);
	if (GetNode(L,elem)){
		printf("\n该节点位于第%d号位上\n", GetNode(L, elem));
	}
	else{
		printf("\n查找失败!\n");
	}
}