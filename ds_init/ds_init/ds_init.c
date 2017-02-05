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
		p->next = rear->next;//βָ���nextʼ����ָ��ͷ����
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
	pb = L->next;//ȡ�õ�һ��Ԫ�ؽڵ�
	pf = pb;
	if (L->next==head)
	{
		printf("\n�ñ�Ϊ�ձ�!\n");
		exit(ERROR);
	}
	if (i<1||i>Node_Nums(L)+1)
	{
		printf("\n����λ������!\n");
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
		printf("\n�������½ڵ������\n");
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
	pb = head->next;//�õ���һ��Ԫ�ؽڵ�
	int count = 1;
	if (L->next==head)
	{
		printf("\n�ñ�Ϊ�ձ�!\n");
	}
	if (i<1||i>Node_Nums(L))
	{
		printf("\nɾ��λ������\n");
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
		printf("%d�Žڵ������Ϊ%d\n",count,pb->data);
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
		printf("\n�ñ��ǿձ�!\n");
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
	printf("\n������Ҫ�����ڵ�ĸ���!\n");
	scanf_s("\n%d", &count);
	L = ds_init(count);
	printf("\n�����ɹ�! ���й���%d���ڵ�\n",Node_Nums(L));
	Show_ds_list(L);
	printf("\n������Ҫ�����λ��\n");
	scanf_s("%d", &insert_position);
	if (ds_insert(L,insert_position)==1)
	{
		printf("\n����ɹ�\n");
		Show_ds_list(L);
	}
	printf("\n������Ҫɾ����λ��\n");
	scanf_s("%d",&delete_position);
	if (ds_delete(L,delete_position)==1){
		printf("\nɾ���ɹ�!\n");
		Show_ds_list(L,delete_position);
	}
	printf("\n��������Ҫ���ҵĽڵ������!\n");
	scanf_s("%d", &elem);
	if (GetNode(L,elem)){
		printf("\n�ýڵ�λ�ڵ�%d��λ��\n", GetNode(L, elem));
	}
	else{
		printf("\n����ʧ��!\n");
	}
}