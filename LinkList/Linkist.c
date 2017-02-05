#include "stdlib.h"  
#include "stdio.h"  
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#define NULL 0
#define OK 1
#define ERROR 0
#define LEN sizeof(struct student)  
#define Status int
typedef struct student Node;
struct student
{
	int num;//ѧ��   
	float score;          //������������Ϣ���Լ��������������ֶ�  
	struct student *next;       //ָ����һ�ڵ��ָ��  
};

int n;  //�ڵ�����   
/*
==========================
���ܣ�����n���ڵ������
���أ�ָ�������ͷ��ָ��
==========================
*/
struct student *Create()
{
	struct student *head;       //ͷ�ڵ�  
	struct student *p1 = NULL;  //p1���洴�����½ڵ�ĵ�ַ  
	struct student *p2 = NULL;  //p2����ԭ�������һ���ڵ�ĵ�ַ  

	n = 0;          //����ǰ����Ľڵ�����Ϊ0��������  
	p1 = (struct student *) malloc(LEN);   //����һ���½ڵ�  
	p2 = p1;            //����ڵ㿪�ٳɹ�����p2�Ȱ�����ָ�뱣�������Ա�����  

	if (p1 == NULL)        //�ڵ㿪�ٲ��ɹ�  
	{
		printf("\nCann't create it, try it again in a moment!\n");
		return NULL;
	}
	else                //�ڵ㿪�ٳɹ�  
	{
		head = NULL;        //��ʼheadָ��NULL  
		printf("������� %d �� ѧ����ѧ��--����:", n + 1);
		scanf_s("%d %f", &(p1->num), &(p1->score));    //¼������  
	}
	while (p1->num != 0)      //ֻҪѧ�Ų�Ϊ0���ͼ���¼����һ���ڵ�  
	{
		n += 1;         //�ڵ���������1��  
		if (n == 1)      //����ڵ�������1����headָ��մ����Ľڵ�p1  
		{
			head = p1;
			p2->next = NULL;  //��ʱ��p2����p1,Ҳ����p1->nextָ��NULL��  
		}
		else
		{
			p2->next = p1;   //ָ���ϴ�����ոտ��ٵ��½ڵ�  
		}

		p2 = p1;            //��p1�ĵ�ַ��p2������Ȼ��p1�����µĽڵ�  

		p1 = (struct student *) malloc(LEN);
		printf("������� %d �� ѧ����ѧ��--����:", n + 1);
		scanf_s("%d %f", &(p1->num), &(p1->score));
	}
	p2->next = NULL;     //�˾���Ǹ��ݵ�����������һ���ڵ�Ҫָ��NULL  

	free(p1);           //p1->numΪ0��ʱ��������whileѭ���������ͷ�p1  
	p1 = NULL;
	printf("�����ɹ�! \n");
	//�ر�Ҫ���ǰ��ͷŵı��������ΪNULL,����ͱ��"Ұָ��"������ַ��ȷ����ָ��  
	return head;        //���ش��������ͷָ��   
}
//             1.��
Node *LinkedListInsert(Node *L, int i)
{
	Node *pre;                      //preΪǰ����� 
	pre = L;
	int tempi = 1;
	for (tempi = 1; tempi < i; tempi++)
		pre = pre->next;  //���ҵ�i��λ�õ�ǰ����� 
	while (tempi<i)
	{
		tempi++;
		pre = pre->next;
	}
	Node *p;                                //����Ľ��Ϊp
	p = (Node *)malloc(sizeof(Node));
	printf("�����������ѧ���� ѧ��--�ܷ�\n");
	scanf_s("%d%f", &(p->num), &(p->score));
	p->next = pre->next;
	pre->next = p;
	printf("����ɹ�!\n");
	return L;
} 
//             2.ɾ
struct student *dele(Node *L, int num){
	Node *pb, *pf, *head;
	head = L;
	pf = NULL;
	pb = head;
	if (head == NULL)
	{
		printf("\n�ñ�Ϊ�ձ�");
		return head;
	}
	while (pb->num != num&&pb != NULL){
		pf = pb;
		pb = pb->next;
	}
	if (pb->num == num)
	{
		if (pb == head)
		{
			head = pb->next;
		}
		else{
			pf->next = pb->next;
		}
		free(pb);
		printf("\nɾ���ɹ�!");
	}
	else{
		printf("\n�������沢û���ҵ���ѧ�ŵ�ѧ��");
	}
	return head;
}
//             3.��
boolean GetStudent(Node *L,int stu_num){
	Node *head, *pb;

}
void ShowLinkList(Node *L){
	Node *pointer, *head;
	head = L;
	pointer = head;
	printf("");
	if (pointer != NULL)
	{
		do
		{
			printf("\n\t#%d��ѧ���ĳɼ�Ϊ%f#", pointer->num, pointer->score);
			pointer = pointer->next;
		} while (pointer != NULL);
	}
	else
	{
		printf("\n�ñ�Ϊ�ձ�\n");
	}
	printf("\n\t\t\t\t\t\t\t**��ǰ����%d��ѧ��**\n", Count_Node_Num(L));
}


int Count_Node_Num(Node *L){
	Node *head, *pointer;
	head = L;
	pointer = head;
	int count = 0;
	while (pointer!=NULL){
		count++;
		pointer = pointer->next;
	}
	return count;
}

void menu(){
	printf("\n\t\t\t                      ѧ����Ϣ����ϵͳ\n");
	printf("\t\t\t#**************************************#\n");
	printf("\t\t\t#                   1.����ѧ����Ϣ��   #\n");
	printf("\t\t\t#                   2.����ѧ����Ϣ     #\n");
	printf("\t\t\t#                   3.ɾ��ѧ����Ϣ     #\n");
	printf("\t\t\t#                   4.�鿴ѧ����Ϣ     #\n");
	printf("\t\t\t#                   0.�˳�             #\n");
}
void main(){
	system("COLOR 9f");
	Node *L=NULL;
	int select;
	int dele_num;
	int insert_position;
	while (1){
		menu();
		printf("�����ּ�ѡ��Ҫ���еĲ���\n");
		scanf_s("%d", &select);
		printf("\n");
		if (select==0){
			break;
		}
		else{
			switch (select){
			case 1:L = Create(); break;
			case 2:printf("���������ӵ�ѧ���Ĳ���λ��\n"); scanf_s("%d", &insert_position);L = LinkedListInsert(L,insert_position); break;
			case 3:printf("�������ɾ���ڵ��ѧ����ѧ��: "); scanf_s("%d", &dele_num); L = dele(L, dele_num); break;
			case 4:ShowLinkList(L); break;
			}
		}
	}
}

